#ifndef GIMBAL_CONTROLLER_H
#define GIMBAL_CONTROLLER_H


#define CTRL_DATA_BUF_LEN 50
#define CONTROL_DELAY_FILTER
#define MOTOR_PULSE_CLOCK 500000
#define PD1 16
#define PS1 17
#define PD2 18
#define PS2 19
#define CT1 5
#define CT2 4
#define CT3 3
#define CT4 2
#define PPR1 1000
#define GEAR1 400
#define PPR2 1000
#define GEAR2 1000
#define PULSE_MAX_FREQ 30000
#define STAB_TRANSFER_TIME 2000.0
#define CONTROL_TIME_STAMP 0.001

#include "stim.h"
#include "ModbusRtu.h"
#define MODBUS_PORT Serial1
Modbus mbMaster(0,MODBUS_PORT,0); 
modbus_t telegram[2];
unsigned long u32wait;
uint16_t au16data[16]; 
uint16_t output16data[16];
uint8_t u8state = 0; //!< machine state
uint8_t u8query = 0; //!< pointer to message query
void modbusSetup()
{
    // telegram 0: read registers
    telegram[0].u8id = 1; // slave address
    telegram[0].u8fct = MB_FC_READ_REGISTERS; // function code (this one is registers read)
    telegram[0].u16RegAdd = 0; // start address in slave
    telegram[0].u16CoilsNo = 16; // number of elements (coils or registers) to read
    telegram[0].au16reg = au16data; // pointer to a memory array in the Arduino

    // telegram 1: write a single register
    telegram[1].u8id = 1; // slave address
    telegram[1].u8fct = MB_FC_WRITE_MULTIPLE_REGISTERS; // function code (this one is write a single register)
    telegram[1].u16RegAdd = 16; // start address in slave
    telegram[1].u16CoilsNo = 16; // number of elements (coils or registers) to write
    telegram[1].au16reg = output16data; // pointer to a memory array in the Arduino

    MODBUS_PORT.begin( 38400 ); // baud-rate
    mbMaster.start();
    mbMaster.setTimeOut( 1000 ); // if there is no answer in 5000 ms, roll over
    u32wait = millis() + 1000;
    u8state = u8query = 0;
}


IntervalTimer controlTimer;
IntervalTimer motorTimer;

IntervalTimer sensorTimer;
static  StimData stim_data;
int mStimMsgCount=0;
//float stim_v_speed =0;
//float stim_h_speed =0;
static void callbackMotorUpdate();
static void callbackUserUpdate();
static void callbackSensorUpdate();
double userAngleh = 0;
double userAnglev = 0;
class CGimbalController
{
private:
    int mStabMode;
    int h_abs_pos,v_abs_pos;
    int userAlive;
    float h_user_speed;
    float v_user_speed;
    int h_ppr,v_ppr;
    int pelco_count;
    //     float h_speed_pps,v_speed_pps;
    float vSpeedFeedback ;
    double hSpeedFeedback ;
    int   control_oldID;
    int stimCount;
    unsigned long lastStimByteTime;
    int pulseMode ;
    float fov;
    int mStimSPS;
    float param_h_p ,param_v_p;
    float param_h_i ,param_v_i;
    float param_h_d ,param_v_d;
    float mUserMaxspdH ; //DPS
    float mUserMaxSpdV ;//DPS
    float maxAccH,maxAccV;
    bool isSetupChanged;
    float vSpeedCalib = 0,hSpeedCalib = 0;
    double sumEv=0,sumEh=0;
public:
    void setCalib(float hcalib,float vcalib);
    void setCT(int c11,int c12,int c21,int c22);
    bool isStimConnected;
    int ct11,ct12,ct21,ct22;
    void reportStat();
    CGimbalController()
    {
    }
    void setMaxAcc(float hvalue,float vvalue)
    {
      maxAccH=hvalue;
      maxAccV=vvalue;
      isSetupChanged = true;
      }
    void initGimbal();
    void setPPR(unsigned int hppr,unsigned int vppr);
    void setKalmanZ(double pn,double sn)
    {
      initKalmanZ(pn,sn);
      }
    int getSensors(){
      return ct11*8+ct12*4+ct21*2+ct22;
      }
    void controlerReport();
    void setControlSpeed(float hspeed,float vspeed);
    bool ps1,ps2;
    void motorUpdate();
    double hinteg=0;
    double vinteg=0;
    double h_control_old=0;
    double v_control_old=0;
    void UserUpdate();
    void setAbsPos (float hpos,float vpos)
    {
      h_abs_pos = hpos/360.0*h_ppr;
      v_abs_pos = vpos/360.0*v_ppr;
    }
    void modbusLoop();
    void readSensorData();
    void setPulseMode(int value);
    int interupt = 0;
    void setStimMode(int value)
    {
        mStabMode = value;
        stim_data.z_angle = 0;
        stim_data.y_angle = 0;
        hPulseBuff = 0;
        vPulseBuff = 0;
        hinteg=0;
        vinteg=0;
        interupt = STAB_TRANSFER_TIME;
        isSetupChanged =true;
        userAngleh = 0;
        userAnglev = 0;
    }
    void setFov(float value);

    void setPARAM_P(float valueh, float valuev);

    void setPARAM_I(float valueh, float valuev);

    void setPARAM_D(float valueh, float valuev);

private:
    int hPulseBuff ;
    int vPulseBuff ;
    int h_pulse_clock_counter;
    int v_pulse_clock_counter;
    int h_freq_devider=100;
    int v_freq_devider=100;
    int minPulsePeriodh,minPulsePeriodv;
    void outputSpeedH(double speeddps);
    void outputSpeedV(double speeddps);
    


} gimbal;


void CGimbalController::setCalib(float hcalib, float vcalib)
{
    vSpeedCalib =vcalib;
    hSpeedCalib = hcalib;

}

void CGimbalController::reportStat()
{
    controlerReport();
    if(getSensors())setStimMode(0);
    if(!isSetupChanged)return;
    isSetupChanged = false;
    mPrint("$MSGS,");

    mPrint(",azi:");
    mPrint(float(h_abs_pos)/(float)h_ppr*360.0);
    mPrint(",ele:");
    mPrint(float(v_abs_pos)/(float)v_ppr*360.0);
    mPrint(",vppr:");
    mPrint(v_ppr);
    mPrint(",hppr:");
    mPrint(h_ppr);
    mPrint(",fov:");
    mPrint(fov);
    mPrint(",stim:");
    mPrint(isStimConnected);
    mPrint(",stab:");
    mPrint(mStabMode);
    mPrint(",pm");
    mPrint(pulseMode);
    mPrint(",hp:");
    mPrint(param_h_p);
    mPrint(",hi:");
    mPrint(param_h_i);
    mPrint(",hd:");
    mPrint(param_h_d);
    mPrint(",sensor:");
    mPrint(ct11);
    mPrint(ct12);
    mPrint(ct21);
    mPrint(ct12);
    mPrint(",pulse:");
    mPrint(hPulseBuff);
    mPrint(",");
    mPrint(vPulseBuff);
    mPrint(",");
    mPrint(hSpeedCalib);
    mPrint(",");
    mPrint(vSpeedCalib);
    mPrint("\n");
    //        controlerReport();
}

void CGimbalController::initGimbal()
{
    mStimSPS=0;
    isSetupChanged = true;
    maxAccH = 0.1;
    maxAccV = 0.1;
    mUserMaxspdH =60.0; //DPS
    mUserMaxSpdV =60.0 ;//DPS
    isStimConnected = false;
    fov = 60;
    mStabMode = 0;
    pulseMode = 1;
    h_abs_pos=0;
    v_abs_pos=0;
    userAlive = 1;
    param_h_p =1.2;
    param_h_i =0.0;
    param_h_d =0.0;
    param_v_p =1.2;
    param_v_i =0.0;
    param_v_d =0.0;
    pinMode(CT1,INPUT);
    pinMode(CT2,INPUT);
    pinMode(CT3,INPUT);
    pinMode(CT4,INPUT);

    pinMode(PD1,OUTPUT);
    pinMode(PS1,OUTPUT);
    pinMode(PD2,OUTPUT);
    pinMode(PS2,OUTPUT);
    digitalWrite(PD1,HIGH);
    delay(200);
    digitalWrite(PS1,HIGH);
    delay(200);
    digitalWrite(PD2,HIGH);
    delay(200);
    digitalWrite(PS2,HIGH);
    delay(500);
    digitalWrite(PD1,LOW);
    delay(200);
    digitalWrite(PS1,LOW);
    delay(200);
    digitalWrite(PD2,LOW);
    delay(200);
    digitalWrite(PS2,LOW);
    delay(200);
    motorTimer.begin(callbackMotorUpdate,1000000.0/MOTOR_PULSE_CLOCK);
    controlTimer.begin(callbackUserUpdate,1000000*CONTROL_TIME_STAMP);
    sensorTimer.begin(callbackSensorUpdate,200);
    Serial.println("gimbal test done");
    modbusSetup();
    Serial.println("Firmware version: 7.0");
    h_user_speed = 0;
    v_user_speed = 0;
    setPPR(PPR1*GEAR1,PPR2*GEAR2);
    //      hPulseBuff = 100000;
    //      vPulseBuff = 200000;
    for(int i=0;i<CTRL_DATA_BUF_LEN;i++)
    {
        //            h_control   [i]=0;
        //            h_control_i [i]=0;
        //            h_control_d [i]=0;
        //            v_control   [i]=0;
        //            v_control_i [i]=0;
        //            v_control_d [i]=0;
    }
    control_oldID = 0;
    h_pulse_clock_counter =0;
    v_pulse_clock_counter =0;
    resetStimState(&stim_data);
}

void CGimbalController::setPPR(unsigned int hppr, unsigned int vppr)
{
    h_ppr = hppr;
    v_ppr = vppr;
    minPulsePeriodh = 4;//MOTOR_PULSE_CLOCK/(h_ppr);
    minPulsePeriodv = 4;//MOTOR_PULSE_CLOCK/(v_ppr);
    if(minPulsePeriodh<4)minPulsePeriodh=4;
    if(minPulsePeriodv<4)minPulsePeriodv=4;
    isSetupChanged =true;
}
double eh,ev;
int timeSec=0; 
void CGimbalController::controlerReport()
{
//    int sensorValue = getSensors();
//    if(sensorValue) reportDebug("Angle limit");
   // float abs_pos_h = h_abs_pos*360.0/h_ppr;
   // float abs_pos_v = v_abs_pos*360.0/v_ppr;
/*
    S_CONTROL.print("$TGC,");
    S_CONTROL.print(h_user_speed);
    S_CONTROL.print(",");
    S_CONTROL.print(v_user_speed);
    S_CONTROL.print(",ct:");
    S_CONTROL.print(ct11);
    S_CONTROL.print(ct12);
    S_CONTROL.print(ct21);
    S_CONTROL.print(ct12);
    S_CONTROL.print(mStimSPS);
    mStimSPS=0;
    S_CONTROL.print(",");
    S_CONTROL.print(pelco_count);
    pelco_count=0;
    S_CONTROL.print(",");
//    S_CONTROL.print(sensorValue);
//    S_CONTROL.print(",");
    S_CONTROL.print(abs_pos_h);
    S_CONTROL.print(",");
    S_CONTROL.print(abs_pos_v);
    S_CONTROL.print(",");
    timeSec++;
    if(timeSec>10)
    {
      timeSec=0;
      eh = sumEh;
      sumEh=0;
      ev=sumEv;
      sumEv=0;
    }
    S_CONTROL.print(eh);
    S_CONTROL.print(",");
    S_CONTROL.print(ev);
    S_CONTROL.print("\n");

    Serial.print("$TGC,");
    Serial.print(h_user_speed);
    Serial.print(",");
    Serial.print(v_user_speed);
    Serial.print(",");
    Serial.print(hSpeedFeedback);
    Serial.print(",");
    Serial.print(vSpeedFeedback);
    Serial.print(",");
    Serial.print(stimCount);
//    Serial.print(",");
//    Serial.print(sensorValue);
    Serial.print(",");
    Serial.print(abs_pos_h);
    Serial.print(",");
    Serial.print(abs_pos_v);
    Serial.print("\n");
*/
}

void CGimbalController::setControlSpeed(float hspeed, float vspeed)
{
    pelco_count++;
    h_user_speed = hspeed * mUserMaxspdH;
    v_user_speed = vspeed * mUserMaxSpdV;
    userAlive =1.0/CONTROL_TIME_STAMP;

}

void CGimbalController::motorUpdate()
{
    h_pulse_clock_counter++;
    v_pulse_clock_counter++;
    if(hPulseBuff!=0)
    {
        if(h_pulse_clock_counter>h_freq_devider)
        {
            h_pulse_clock_counter=0;

            if(hPulseBuff>0)
            {
                hPulseBuff--;
                h_abs_pos++;
            }
            else
            {
                hPulseBuff++;
                h_abs_pos--;
            }
            if(pulseMode==1)
            {
                ps1=!ps1;
                digitalWrite(PS1,ps1);
            }
            else if(pulseMode==2)
            {
                if(hPulseBuff<0){
                    if(hPulseBuff%2)digitalWrite(PS1,HIGH);
                    else digitalWrite(PS1,LOW);
                    digitalWrite(PD1,HIGH);
                }
                else{
                    if(hPulseBuff%2)digitalWrite(PD1,HIGH);
                    else digitalWrite(PD1,LOW);
                    digitalWrite(PS1,HIGH);
                }
            }

        }
    }
    //vPulse;
    if(vPulseBuff!=0)
    {
        if(v_pulse_clock_counter>v_freq_devider)
        {
            v_pulse_clock_counter=0;
            if(vPulseBuff>0)
            {
                vPulseBuff--;
                v_abs_pos++;
            }
            else
            {
                vPulseBuff++;
                v_abs_pos--;
            }

            if(pulseMode==1)
            {
                //                    if(vPulseBuff%2)digitalWrite(PS2,HIGH);
                //                    else digitalWrite(PS2,LOW);
                ps2=!ps2;
                digitalWrite(PS2,ps2);
            }
            else if(pulseMode==2)
            {
                if(vPulseBuff<0){
                    if(vPulseBuff%2)digitalWrite(PS2,HIGH);
                    else digitalWrite(PS2,LOW);
                    digitalWrite(PD2,HIGH);
                }
                else{
                    if(vPulseBuff%2)digitalWrite(PD2,HIGH);
                    else digitalWrite(PD2,LOW);
                    digitalWrite(PS2,HIGH);
                }
            }
        }
    }
}

void CGimbalController::UserUpdate()//
{
    modbusLoop();
    if(userAlive>0)userAlive--;
    else
    {
        h_user_speed*=0.6;
        v_user_speed*=0.6;
    }

    isStimConnected = (mStimMsgCount>0);
    stimCount = mStimMsgCount;
    mStimMsgCount=0;
    if(interupt>0)interupt--;
    if(mStabMode==0)
    {
        // horizontal control value
        outputSpeedH(h_user_speed);
        // vertical control value
        outputSpeedV(v_user_speed);
    }
    else if (mStabMode==1)
    {
        //rotate control index
        userAngleh+=h_user_speed*CONTROL_TIME_STAMP;
        //            int control_newID = control_oldID+1;
        //            if(control_newID>=CTRL_DATA_BUF_LEN)control_newID=0;
        double h_control = stim_data.z_angle+userAngleh;
        if(interupt>0){
        h_control*=(STAB_TRANSFER_TIME-interupt)/STAB_TRANSFER_TIME;
        }
        sumEh+=abs(h_control);
        double h_control_dif = (h_control - h_control_old)/CONTROL_TIME_STAMP;//h_control[control_newID] - h_control[control_oldID];
        h_control_old = h_control;
        //            double h_control_i = -stim_data.z_angle;
        //            h_control_i [control_newID] = 0;
//        if(abs(h_control)<2)
        hinteg += h_control ;
//        else hinteg+=//  [control_newID];
        userAnglev+=v_user_speed*CONTROL_TIME_STAMP;
        //            int control_newID = control_oldID+1;
        //            if(control_newID>=CTRL_DATA_BUF_LEN)control_newID=0;
        double v_control = -stim_data.y_angle+userAnglev;
        if(interupt>0){
        v_control*=(STAB_TRANSFER_TIME-interupt)/STAB_TRANSFER_TIME;
        }
        sumEv+=abs(v_control);
        double v_control_dif= (v_control - v_control_old)/CONTROL_TIME_STAMP;//h_control[control_newID] - h_control[control_oldID];
        v_control_old = v_control;
        //            double h_control_i = -stim_data.z_angle;
        //            h_control_i [control_newID] = 0;
//        if(abs(v_control)<5)
        vinteg += v_control ;
//        else vinteg+=5;
        double output_value =   h_control *param_h_p+ h_control_dif*param_h_d+ hinteg*param_h_i;
        
        outputSpeedH(output_value);

        output_value =   v_control *param_v_p+ v_control_dif*param_v_d+ vinteg*param_v_i;
        
        outputSpeedV(output_value);

    }


    //        float outputVal = h_user_speed;
    //        Serial.println(outputVal);
    //        stim_data.z_angle+=outputVal;


    //        Serial.print(output_value);
    //        Serial.print(" ");

    //        v_control   [control_newID] = v_user_speed - stimrate_v;
    //        v_control_d [control_newID] = v_control[control_newID]-v_control[control_oldID];
    //        v_control_i [control_newID] = v_control[control_newID]+v_control[control_oldID];
    //        output_value =   v_control    [control_newID]*PARAM_P
    //                + v_control_i[control_newID]*PARAM_I
    //                + v_control_d[control_newID]*PARAM_D;

    //        Serial.print(output_value);
    //        Serial.print("\n");
    //        status_report(stim_data.x_rate,stim_data.y_rate,stim_data.z_rate,stim_data.msgCount,h_abs_pos,v_abs_pos);

}

void CGimbalController::modbusLoop() {
    switch( u8state ) {
    case 0:
        if (millis() > u32wait) u8state++; // wait state
        break;
    case 1:

        if(u8query==1)//send status over modbus
        {
            output16data[ 0] = fov*100;
            output16data[ 1] = abs(hPulseBuff*100);
            output16data[ 2] = abs(vPulseBuff*100);
            output16data[ 3] = abs(float(h_abs_pos)/(float)h_ppr*36000);
            output16data[ 4] = abs(float(v_abs_pos)/(float)v_ppr*36000);
            output16data[ 5] = abs(h_ppr/2000*100);
            output16data[ 6] = abs(v_ppr/2000*100);
            output16data[ 7] = abs(pelco_count*100);pelco_count=0;
            output16data[ 8] = abs(mStimSPS*100);    mStimSPS=0;
            output16data[ 9] = abs(param_h_p*100);
            output16data[10] = abs(param_h_i*100);
            output16data[11] = abs(param_h_d*100);
            output16data[12] = abs(mStabMode*100);
            output16data[13] = abs(getSensors()*100);
        }
        mbMaster.query( telegram[u8query] ); // send query (only once)
        u8state++;
        u8query++;
        if (u8query >= 2) u8query = 0;
        break;
    default:
        mbMaster.poll(); // check incoming messages
        if (mbMaster.getState() == COM_IDLE) {
            u8state = 0;
            u32wait = millis() + 10;
            gimbal.setCT(au16data[0],au16data[1],au16data[2],au16data[3]);//update data after modbus communication done
        }
        break;
    }

    //analogRead( 0 );

}

void CGimbalController::readSensorData()//200 microseconds
{
    //      controlerReport();
    while (S_STIM.available() > 0) {
        unsigned long timeMicros = micros();
        unsigned char databyte = S_STIM.read();
        if(readStim(databyte,(timeMicros-lastStimByteTime), &stim_data))// one packet per millisencond
        {
            mStimMsgCount++;
            mStimSPS++;
            //                stim_v_speed += stim_data.y_rate;
            //                stim_h_speed += stim_data.z_rate;
            //              outputSpeedH(-(0.8*stim_data.z_angle
            //                              +0.0*stim_data.z_rate
            //                              +0.0*stim_data.z_acc));
        }
        lastStimByteTime = timeMicros;
    }

}

void CGimbalController::outputSpeedH(double speeddps)//speed in degrees per sec
{
    if(ct11>0){
        hPulseBuff=h_ppr/360.0*CONTROL_TIME_STAMP;
    }
    else if(ct12>0){
        hPulseBuff=-h_ppr/360.0*CONTROL_TIME_STAMP;
    }
    else{
        double h_speed_pps = speeddps/360.0*h_ppr;
        hPulseBuff += int(h_speed_pps*CONTROL_TIME_STAMP*2);//
        int maxBuf=h_ppr/4;
        if(hPulseBuff > maxBuf )hPulseBuff = maxBuf;
        if(hPulseBuff < -maxBuf)hPulseBuff = -maxBuf;
    }
    if(hPulseBuff==0)h_freq_devider = h_ppr*1000;
    else
    {
        h_freq_devider=1+CONTROL_TIME_STAMP*(float)MOTOR_PULSE_CLOCK/abs(hPulseBuff);
        if(h_freq_devider<minPulsePeriodh)h_freq_devider=minPulsePeriodh;

 
    }
    if(pulseMode==1)
    {
        int dir = LOW;
        if(hPulseBuff>0)
        {
            dir=LOW;
        }
        else
        {
            dir = HIGH;
        }

        digitalWrite(PD1, dir);
    }
}
void CGimbalController::outputSpeedV(double speeddps)//speed in degrees per sec
{
    if(ct21>0){
        vPulseBuff=v_ppr/360*CONTROL_TIME_STAMP;
    }
    else if(ct22>0){
        vPulseBuff=-v_ppr/360*CONTROL_TIME_STAMP;
    }
    else{
        double speed_pps = speeddps/360.0*v_ppr;
        vPulseBuff += int(speed_pps*CONTROL_TIME_STAMP*2);//
        int maxBuf=v_ppr/4;
        if(vPulseBuff > maxBuf )vPulseBuff = maxBuf;
        if(vPulseBuff < -maxBuf)vPulseBuff = -maxBuf;
    }
    if(vPulseBuff==0)v_freq_devider = v_ppr*1000;
    else
    {
        v_freq_devider=1+CONTROL_TIME_STAMP*(float)MOTOR_PULSE_CLOCK/abs(vPulseBuff);
        if(v_freq_devider<minPulsePeriodv)v_freq_devider=minPulsePeriodv;
    }
    if(pulseMode==1)
    {
        int dir = LOW;
        if(vPulseBuff>0)
        {
            dir=LOW;
        }
        else
        {
            dir = HIGH;
        }
        digitalWrite(PD2, dir);
    }

}

void CGimbalController::setFov(float value)
{
    if(value>0.1&&value<=60.0)
    {
        fov = value;
        mUserMaxspdH = fov;
        mUserMaxSpdV = fov;
//        reportDebug("fov changed");
//        reportDebug(fov);
//        isSetupChanged =true;
    }
    else
    {
//        reportDebug("fov invalid");
    }

}
void CGimbalController::setCT(int c11,int c12,int c21,int c22)
{
    ct11 = c11;
    ct12 = c12;
    ct21 = c21;
    ct22 = c22;
  
}
void CGimbalController::setPARAM_P(float valueh,float valuev)
{
    param_h_p = valueh;
    param_v_p = valuev;
//    reportDebug("param p updated");
    isSetupChanged =true;
}

void CGimbalController::setPARAM_I(float valueh,float valuev)
{
    param_h_i = valueh;
    param_v_i = valuev;
//    reportDebug("param i updated");
    isSetupChanged =true;
}

void CGimbalController::setPARAM_D(float valueh, float valuev)
{
    param_h_d = valueh;
    param_v_d = valuev;
//    reportDebug("param d updated");
    isSetupChanged =true;
}

void CGimbalController::setPulseMode(int value)
{
    if(value>0&&value<3)
    {
        pulseMode = value;
        reportDebug("pulse mode changed");
        isSetupChanged =true;
    }
    else
    {
        reportDebug("pulse mode invalid");
    }
}
static void callbackMotorUpdate()
{
    gimbal.motorUpdate();
}
static void callbackUserUpdate()
{
    gimbal.UserUpdate();
}
static void callbackSensorUpdate()
{
    gimbal.readSensorData();
}
#endif // GIMBAL_CONTROLLER_H
