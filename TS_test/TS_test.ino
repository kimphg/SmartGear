#include "common.h"
#include "gimbal_controller.h"

extern CGimbalController gimbal;
//IntervalTimer  reportTimer;
int             s1_count = 0;
int             s2_count = 0;
int             s3_count = 0;
extern int com_mode;
int msg_count=0;
int generalState = 1;
int buzz = 0;
int idleCount = 0;
void stateReport()
{
    gimbal.reportStat(idleCount/1000);
    if(idleCount<1000000)
      reportDebug("CPU overload",idleCount/1000.0);
    idleCount = 0;
    if((com_mode==3)&&(!s3_count))
    {
        com_mode = 2;
        buzz=150;
        reportDebug("485 mode");
    }
    else if((com_mode==2)&&(!s2_count))
    {
        com_mode = 1;
        buzz=150;
        reportDebug("serial mode");
    }
    else if((com_mode==1)&&(!s1_count))
    {
        com_mode = 3;
        buzz=150;
        reportDebug("ethernet mode");
    }
    //    reportDebug(msg_count);
    if(!gimbal.isStimConnected)buzz+=300;
    s3_count = 0;
    s2_count = 0;
    msg_count = 0;
    //    if(gimbal.getSensors())buzz=1000;
}
void setup() {
    com_mode =3;
    pinMode(20,OUTPUT);
    //    digitalWrite(20,HIGH);
    //    tone(20,2000,500);
    buzz=100;
    gimbal.initGimbal();
    S_STIM.begin(460800);
    Serial.begin(115200);
    Serial1.begin(38400);
    //    S_CONTROL.begin(38400);
    E_CONTROL.begin(19200);
    pinMode(13,OUTPUT);
    reportDebug("Controller start up");
    S_STIM.print("stim test msg");
//    reportTimer.begin(stateReport, 1000000);
    //    modbusino_slave.setup(38400);
    //MODBUS_PORT.begin(38400);

}
int time_stamp_old;
int times = 0;
void loop() {
    int newtimes = millis()/1000;
    if(newtimes!=times)
    {
      times = newtimes;
      stateReport();
    }
    idleCount++;
    readSerialdata();
}
void readSerialdata()
{
    
    //read stim data
    if(com_mode==1)
        while (Serial.available() > 0) {
            //            digitalWrite(13, HIGH);
            unsigned char databyte = Serial.read();
            if( readPelco(databyte))s1_count++;
        }
    //    if(com_mode==2)
    //        while (S_CONTROL.available() > 0) {
    //            digitalWrite(13, HIGH);
    //            unsigned char databyte = S_CONTROL.read();
    //            if( readPelco(databyte))s2_count++;
    //        }
    if(com_mode==3)
        while (E_CONTROL.available() > 0) {
            
            unsigned char databyte = E_CONTROL.read();
            if( readPelco(databyte))s3_count++;
        }
    //  Serial.println("loop");
    //    Serial1.println("loop");
    
    
}

int pelco_byte_count = 0;
struct PelcoData{
    float x_rate,y_rate;
} pelco_data;
/*
 *
Pelco-D   Bit 7     Bit 6     Bit 5     Bit 4             Bit 3         Bit 2       Bit 1     Bit 0
Command 1 Sense     Reserved  Reserved  Auto/manual scan  Camera on/off Iris close  Iris open Focus near
Command 2 Focus far Zoom tele Zoom wide Tilt down         Tilt up       Pan left    Pan right Fixed to 0
 */
//unsigned char pelcoOldByte=0;
unsigned long pelcoLastTime = 0;
unsigned char serial_input_buff[20];
int serial_input_id=0;
unsigned char pelco_input_buff[7];

bool processPelco(){
    //    unsigned char command1 = pelco_input_buff[2];
    unsigned char command2 = pelco_input_buff[3];
    int panSpeed = (unsigned char)pelco_input_buff[4];
    int tiltSpeed = (unsigned char)pelco_input_buff[5];
    if((command2&0x01)==0x00&&(pelco_input_buff[1]==0x01))//standart pelco
    {
        float panDir = 1, tiltDir = 1;
        if( (command2&0x02) && (!(command2&0x04)) )//right
        {
            panDir = 1;
            //                    Serial.print("+");
        }
        else if ((command2&0x04) && (!(command2&0x02)) )//left
        {
            panDir = -1;
            //                    Serial.print("-");
        }
        if( (command2&0x08) && (!(command2&0x10)) )//up
        {
            tiltDir = 1;
            //                    Serial.print("*");
        }
        else if ((command2&0x10) && (!(command2&0x08)) )
        {
            tiltDir = -1;
            //                    Serial.print("/");
        }
        //                Serial.print(".");
        gimbal.setControlSpeed(panSpeed*panDir/255.0,tiltSpeed*tiltDir/255.0);
        //                digitalWrite(20,HIGH);
        //                S_CONTROL.print("$MSG,std Pelco,");
        //                S_CONTROL.print(panSpeed*panDir);
        //                S_CONTROL.print(",");
        //                S_CONTROL.println(tiltSpeed*tiltDir);
    }
    else if(pelco_input_buff[1]==0x02) //control setup
    {
        gimbal.setFov( ( ( ((unsigned char)pelco_input_buff[2])<<8) + (unsigned char)pelco_input_buff[3])/65535.0*100.0);
        gimbal.setPulseMode(  pelco_input_buff[4]);
        gimbal.setStimMode(  pelco_input_buff[5]);
        reportDebug("FovPS set");
    }
    else if(pelco_input_buff[1]==0x03) //P setup
    {
        float ph = ( ( ((unsigned char)pelco_input_buff[2])<<8) + (unsigned char)pelco_input_buff[3])/65535.0*800.0-400.0;
        float pv = ( ( ((unsigned char)pelco_input_buff[4])<<8) + (unsigned char)pelco_input_buff[5])/65535.0*800.0-400.0;
        gimbal.setPARAM_P(ph,pv);
        reportDebug("PH:",ph);
        reportDebug("PV:",pv);
    }
    else if(pelco_input_buff[1]==0x04) //I setup
    {
        float ph = ( ( ((unsigned char)pelco_input_buff[2])<<8) + (unsigned char)pelco_input_buff[3])/65535.0*20.0-10.0;
        float pv = ( ( ((unsigned char)pelco_input_buff[4])<<8) + (unsigned char)pelco_input_buff[5])/65535.0*20.0-10.0;
        gimbal.setPARAM_I(ph,pv);
        reportDebug("I set");
    }
    else if(pelco_input_buff[1]==0x05) //D setup
    {
        float ph = ( ( ((unsigned char)pelco_input_buff[2])<<8) + (unsigned char)pelco_input_buff[3])/65535.0*20.0-10.0;
        float pv = ( ( ((unsigned char)pelco_input_buff[4])<<8) + (unsigned char)pelco_input_buff[5])/65535.0*20.0-10.0;
        gimbal.setPARAM_D(ph,pv);
        reportDebug("D set");
    }
    else if(pelco_input_buff[1]==0x06) //PPR setup
    {
        unsigned int hppr = ( ( ((unsigned char)pelco_input_buff[2])<<8) + (unsigned char)pelco_input_buff[3])*100;
        unsigned int vppr = ( ( ((unsigned char)pelco_input_buff[4])<<8) + (unsigned char)pelco_input_buff[5])*100;
        //        gimbal.setPPR(hppr,vppr);
        reportDebug("PPR not set");
    }
    else if(pelco_input_buff[1]==0x07) //max acceleration set
    {
        float hacc = ( ( ((unsigned char)pelco_input_buff[2])<<8) + (unsigned char)pelco_input_buff[3])*0.001;
        float vacc = ( ( ((unsigned char)pelco_input_buff[4])<<8) + (unsigned char)pelco_input_buff[5])*0.001;
        gimbal.setMaxAcc(hacc,vacc);
        reportDebug("acc set");
    }
    else if(pelco_input_buff[1]==0x08) //abs pos set
    {
        float hpos = ( ( ((unsigned char)pelco_input_buff[2])<<8) + (unsigned char)pelco_input_buff[3])/65535.0*360-180;
        float vpos = ( ( ((unsigned char)pelco_input_buff[4])<<8) + (unsigned char)pelco_input_buff[5])/65535.0*360-180;
        gimbal.setAbsPos(hpos,vpos);
        reportDebug("Position set");
    }
    else if(pelco_input_buff[1]==0x09) //gyro bias set
    {
        double hpos = ( ( ((unsigned char)pelco_input_buff[2])<<8) + (unsigned char)pelco_input_buff[3])/65535.0*2.0-1.0;
        double vpos = ( ( ((unsigned char)pelco_input_buff[4])<<8) + (unsigned char)pelco_input_buff[5])/65535.0*2.0-1.0;
        gimbal.setCalib(hpos,vpos);
        reportDebug("Calib set");
    }else if(pelco_input_buff[1]==0x0A) //gyro bias set
    {
        double pn = ( ( ((unsigned char)pelco_input_buff[2])<<8) + (unsigned char)pelco_input_buff[3])/65535.0*100;
        double sn = ( ( ((unsigned char)pelco_input_buff[4])<<8) + (unsigned char)pelco_input_buff[5])/65535.0*100;
        gimbal.setKalmanZ(pn,sn);
        reportDebug("Kalman filter set");
    }
    else if(pelco_input_buff[1]==0x0C) //ct set
    {
        int ct11 = pelco_input_buff[2];
        int ct12 = pelco_input_buff[3];
        int ct21 = pelco_input_buff[4];
        int ct22 = pelco_input_buff[5];
        gimbal.setCT(ct11,ct12,ct21,ct22);
        //        reportDebug("Calib set");
    }
    else if(pelco_input_buff[1]==0x0D) //work mode set
    {
        int workmode = pelco_input_buff[2];
        gimbal.setWorkmode(workmode);
         reportDebug("work mode set");
    }
    else {
        //reportDebug("msge");
        //reportDebug(pelco_input_buff[1]);
        return false;
    }
    msg_count++;
    return true;
}

bool readPelco(unsigned char databyte)
{
    serial_input_id++;if(serial_input_id>=20)serial_input_id=0;
    serial_input_buff[serial_input_id] = databyte;
    int id = serial_input_id-6;
    if(id<0)id+=20;
    if(serial_input_buff[id]==0xff)
    {
        unsigned char checkSum =0;
        for(int k = 1;k<6;k++)
        {
            int id = serial_input_id-k;
            if(id<0)id+=20;
            checkSum+=(unsigned char)( serial_input_buff[id]);
        }
        if(checkSum==databyte)
        {


            for(int k = 0;k<7;k++)
            {
                id = serial_input_id-k;
                if(id<0)id+=20;
                pelco_input_buff[6-k] =  serial_input_buff[id];
                
            }
            //            reportDebug("1");
            return processPelco();
            
        }
        //        else reportDebug("0");
    }
    return false;
}
