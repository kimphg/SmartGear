#ifndef GIMBAL_CONTROLLER_H
#define GIMBAL_CONTROLLER_H

//float resultArray[2000];
//int resultArrayId=0;
#define CTRL_DATA_BUF_LEN 50
#define CONTROL_DELAY_FILTER
#define MOTOR_PULSE_CLOCK 1000000
#define PD1 16
#define PS1 17
#define PD2 18
#define PS2 19
#define CT1 5

#define CT2 4
#define CT3 3
#define CT4 2
#define PPR1 1000
#define GEAR1 160
#define PPR2 1000
#define GEAR2 400
#define PULSE_MAX_FREQ 30000
#define STAB_TRANSFER_TIME 2000.0
#define CONTROL_TIME_STAMP 0.001
float MAX_ACC = 5;
float MAX_ACC_H = 1;
#include "stim.h"
//#include "ModbusRtu.h"
//#define MODBUS_PORT Serial1
//Modbus mbMaster(0,MODBUS_PORT,0); 
//modbus_t telegram[2];
int modbus_idle_t =100;
unsigned long u32wait;
//uint16_t au16data[16]; 
//uint16_t output16data[16];
uint8_t u8state = 0; //!< machine state
uint8_t u8query = 0; //!< pointer to message query
double max_stab_spd = 90;
float gyroX;
//void modbusSetup()
//{
//    // telegram 0: read registers
//    telegram[0].u8id = 1; // slave address
//    telegram[0].u8fct = MB_FC_READ_REGISTERS; // function code (this one is registers read)
//    telegram[0].u16RegAdd = 0; // start address in slave
//    telegram[0].u16CoilsNo = 16; // number of elements (coils or registers) to read
//    telegram[0].au16reg = au16data; // pointer to a memory array in the Arduino
//    // telegram 1: write a single register
//    telegram[1].u8id = 1; // slave address
//    telegram[1].u8fct = MB_FC_WRITE_MULTIPLE_REGISTERS; // function code (this one is write a single register)
//    telegram[1].u16RegAdd = 16; // start address in slave
//    telegram[1].u16CoilsNo = 16; // number of elements (coils or registers) to write
//    telegram[1].au16reg = output16data; // pointer to a memory array in the Arduino
//    MODBUS_PORT.begin( 38400 ); // baud-rate
//    mbMaster.start();
//    mbMaster.setTimeOut( 50 ); // if there is no answer in 50 ms, roll over
//    u32wait = millis() + 50;
//    u8state = u8query = 0;
//}


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
public:
    CGimbalController()
    {
    }
private:
    int mStabMode;
    int h_abs_pos,v_abs_pos;
    int userAlive;
    double h_user_speed;
    double v_user_speed;
    int h_ppr,v_ppr;
    int pelco_count;
    float controlDtime = 0;
    long int lastControlTime = 0;
    //     float h_speed_pps,v_speed_pps;
    float  vSpeedFeedback ;
    double hSpeedFeedback ;
    int    control_oldID;
    int    stimCount;
    unsigned long lastStimByteTime;
    int    pulseMode ;
    float  fov;
    int    mGyroCount;
    float  param_h_p ,param_v_p;
    float  param_h_i ,param_v_i;
    float  param_h_d ,param_v_d;
    float  mUserMaxspdH ; //DPS
    float  mUserMaxSpdV ;//DPS
    float  maxAccH,maxAccV;
    bool   isSetupChanged;
    float  vSpeedCalib = 0,hSpeedCalib = 0;
//    double sumEv=0,sumEh=0;
    int    workMode=0;
    double h_control=0,v_control=0;
    double userEle=0, userAzi=0;
public:
    int stimCon = 0;
    void setCalib(double hcalib,double vcalib);
    void setCT(int c11,int c12,int c21,int c22);
    bool isStimConnected;
    int  ct11,ct12,ct21,ct22;
    void reportStat(int idleCount);
    
    void setMaxAcc(float hvalue,float vvalue)
    {
        maxAccH=hvalue;
        maxAccV=vvalue;
        isSetupChanged = true;
//        reportDebug("acc",maxAccH);
    }
    void setWorkmode(int mode)
    {
        workMode = mode;
        
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
        userEle = 0;
        userAzi = 0;
        hPulseBuff = 0;
        vPulseBuff = 0;
        hinteg=0;
        vinteg=0;
        h_control_old = 0;
        v_control_old = 0;
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
    double hPulseBuff ;
    double vPulseBuff ;
    int h_pulse_clock_counter;
    int v_pulse_clock_counter;
    int h_freq_devider=100;
    int v_freq_devider=100;
    int minPulsePeriodh,minPulsePeriodv;
    void outputSpeedH(double speeddps);
    void outputSpeedV(double speeddps);
    
} gimbal;


void CGimbalController::setCalib(double hcalib, double
                                 vcalib)
{
    vSpeedCalib =vcalib;
    hSpeedCalib = hcalib;
    stim_data.y_bias = vSpeedCalib;
    stim_data.z_bias = hSpeedCalib;
}

void CGimbalController::reportStat(int idleCount)
{
    if(getSensors())setStimMode(0);
    pelco_count=0;
    stimCon = mGyroCount/10;
    mGyroCount=0;
    if(!isSetupChanged)return;
    isSetupChanged = false;
    return;

    //        controlerReport();
}

void CGimbalController::initGimbal()
{
    mGyroCount=0;
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
    sensorTimer.begin(callbackSensorUpdate,300);
    Serial.println("gimbal test done");
    //    modbusSetup();
    workMode=1;
    reportDebug("Firmware version: 2.1.2");
    h_user_speed = 0;
    v_user_speed = 0;
    setPPR(PPR1*GEAR1,PPR2*GEAR2);
    setMaxAcc(1,1);
    control_oldID = 0;
    h_pulse_clock_counter =0;
    v_pulse_clock_counter =0;
    resetStimState(&stim_data);
}

void CGimbalController::setPPR(unsigned int hppr, unsigned int vppr)
{
    h_ppr = hppr;
    v_ppr = vppr;
    minPulsePeriodh = 6;//MOTOR_PULSE_CLOCK/(h_ppr);
    minPulsePeriodv = 6;//MOTOR_PULSE_CLOCK/(v_ppr);

    isSetupChanged =true;
}
double eh,ev;
int timeSec=0; 
void CGimbalController::controlerReport()
{

}

void CGimbalController::setControlSpeed(float hspeed, float vspeed)
{
    pelco_count++;
    
    h_user_speed += 0.5*(hspeed * mUserMaxspdH-h_user_speed);
    v_user_speed += 0.5*(vspeed * mUserMaxSpdV-v_user_speed);

    userAlive =0.3/CONTROL_TIME_STAMP;

}

void CGimbalController::motorUpdate()
{
    h_pulse_clock_counter++;
    v_pulse_clock_counter++;
    
    if(abs(hPulseBuff)>=1)
    {
        if(h_pulse_clock_counter>h_freq_devider)
        {
            h_pulse_clock_counter=0;

            //            if(hPulseBuff>0)
            //            {
            //                hPulseBuff--;
            ////                h_abs_pos++;
            //            }
            //            else
            //            {
            //                hPulseBuff++;
            ////                h_abs_pos--;
            //            }
            if(pulseMode==1)
            {
                ps1=!ps1;
                digitalWriteFast(PS1,ps1);
            }
            else if(pulseMode==2)
            {
                //                if(hPulseBuff<0){
                //                    if(hPulseBuff%2)digitalWriteFast(PS1,HIGH);
                //                    else digitalWriteFast(PS1,LOW);
                //                    digitalWriteFast(PD1,HIGH);
                //                }
                //                else{
                //                    if(hPulseBuff%2)digitalWriteFast(PD1,HIGH);
                //                    else digitalWriteFast(PD1,LOW);
                //                    digitalWriteFast(PS1,HIGH);
                //                }
            }

        }
    }
    //vPulse;
    if(abs(vPulseBuff)>=1)
    {
        if(v_pulse_clock_counter>v_freq_devider)
        {
            v_pulse_clock_counter=0;
            //            if(vPulseBuff>0)
            //            {
            //                vPulseBuff-=1;
            ////                v_abs_pos++;
            //            }
            //            else
            //            {
            //                vPulseBuff+=1;
            ////                v_abs_pos--;
            //            }

            if(pulseMode==1)
            {
                //                    if(vPulseBuff%2)digitalWrite(PS2,HIGH);
                //                    else digitalWrite(PS2,LOW);
                ps2=!ps2;
                digitalWriteFast(PS2,ps2);
            }
            else if(pulseMode==2)
            {
                if(vPulseBuff<0){
                    if(int(vPulseBuff)%2)digitalWriteFast(PS2,HIGH);
                    else digitalWriteFast(PS2,LOW);
                    digitalWriteFast(PD2,HIGH);
                }
                else{
                    if(int(vPulseBuff)%2)digitalWriteFast(PD2,HIGH);
                    else digitalWriteFast(PD2,LOW);
                    digitalWriteFast(PS2,HIGH);
                }
            }
        }
    }
}
int h_user = 0;
int v_user = 0;
void CGimbalController::UserUpdate()//
{
    
    if(userAlive>0)
    {
        userAlive--;
    }
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
        //h control calculation
//        h_control = h_user_speed + stim_data.z_rate;// +userAngleh;
//        double h_control_dif = h_control-h_control_old;//
//        h_control_old = h_control;
//        if(interupt>0){
//            h_control*=(STAB_TRANSFER_TIME-interupt)/STAB_TRANSFER_TIME;
//        }
////        sumEh+=abs(h_control);
//        
//        hinteg += h_control ;
//        if(hinteg>5)hinteg=5;
//        if(hinteg<-5)hinteg=-5;
//        //v control calculation
//        //userAnglev+=v_user_speed*CONTROL_TIME_STAMP;
//        v_control = v_user_speed - stim_data.y_rate;
//        //       userEle += v_user_speed/.
//        double v_control_dif = v_control-v_control_old;
//        v_control_old = v_control;
//        if(interupt>0){
//            v_control*=(STAB_TRANSFER_TIME-interupt)/STAB_TRANSFER_TIME;
//        }
////        sumEv+=abs(v_control);
//        vinteg += v_control ;
//        if(vinteg>5)vinteg=5;
//        if(vinteg<-5)vinteg=-5;
//        outputSpeedH(h_control *param_h_p+ h_control_dif*param_h_d+ hinteg*param_h_i);
//
//        outputSpeedV(v_control *param_v_p+ v_control_dif*param_v_d+ vinteg*param_v_i);

    }
    else if (mStabMode == 2)//closed loop for horizontal and openloop for vertical
    {
        //h control calculation
        h_control = h_user_speed*0.25  + stim_data.y_rate;
        hinteg += h_control*CONTROL_TIME_STAMP;
        double h_control_dif = (h_control - h_control_old)/CONTROL_TIME_STAMP;//
        h_control_old = h_control;
        outputSpeedH(h_control*param_h_p*4 + hinteg*param_h_i*80 + h_control_dif*param_h_d);
        //end h control calculation
        //v control calculation         
        v_control = 0 - gyroX*param_v_p - stim_data.z_rate*param_v_d;
        userEle += v_user_speed*CONTROL_TIME_STAMP/12.0;
        double v_control_i = (userEle-stim_data.z_angle )*param_v_i * 60 ;

        outputSpeedV(v_control + v_control_i );
        

    }
    //    modbusLoop();



}

//void CGimbalController::modbusLoop() {
//    switch( u8state ) {
//    case 0:
//        if (millis() > u32wait) u8state++; // wait state
//        break;
//    case 1:
//        if(u8query==1)//send status over modbus
//        {
//            output16data[ 0] = fov*100;
//            output16data[ 1] = abs(hPulseBuff*100);
//            output16data[ 2] = abs(vPulseBuff*100);
//            output16data[ 3] = abs(stim_data.y_angle*100+18000);
//            output16data[ 4] = abs(stim_data.y_rate*100+18000);
//            output16data[13] = abs(getSensors()*100);
//            output16data[14] = controlDtime*100;
//        }
////        mbMaster.query( telegram[u8query] ); // send query (only once)
//        u8state++;
//        u8query++;
//        if (u8query >= 2) u8query = 0;
//        break;
//    default:
//        mbMaster.poll(); // check incoming messages
//        if (mbMaster.getState() == COM_IDLE) {
//            u8state = 0;
//            u32wait = millis() + modbus_idle_t;
//            //update data after modbus communication done
//            //gimbal.setCT(au16data[0],au16data[1],au16data[2],au16data[3]);
//        }
//        break;
//    }
//
//    //analogRead( 0 );
//
//}
unsigned char rawgyro[16];
unsigned char lastbyteGyro;
int gyroByteIndex = -1;
int rawgyroX=0;
double sumGyroX=0;
int countGyroX=0;
float biasGyroX = 0.25;
void CGimbalController::readSensorData()//200 microseconds
{
    //      controlerReport();
    while (S_STIM.available() > 0) {
        unsigned long timeMicros = micros();
        unsigned char databyte = S_STIM.read();
        if(readStim(databyte,(timeMicros-lastStimByteTime), &stim_data))// one packet per millisencond
        {
            mStimMsgCount++;
            mGyroCount++;
            //stim_data.z_angle
            //            Serial.println(stim_data.z_angle);
            //            Serial.print('\n');
            if(workMode==0)E_CONTROL.println(stim_data.y_rate);
        }
        lastStimByteTime = timeMicros;
    }
    while (Serial1.available() > 0) {
        unsigned char databyte = Serial1.read();
        if(databyte == 0x7f)
        {
            if(lastbyteGyro == 0x7f)
            {
                gyroByteIndex = 0;

            }

        }
        
        if(gyroByteIndex>=0)
        {
            if(gyroByteIndex==15)
            {
                unsigned char checksumbyte =  0;
                for (   int i =1;i<15;i++     )
                {
                    checksumbyte^=rawgyro[i];
                }
                if (checksumbyte==databyte)//true msg received
                {


                    //                mStimMsgCount++;
                    mGyroCount++;
                    int newgyroX = rawgyro[1]+rawgyro[2]*256;
                    if(newgyroX>=32768)
                        newgyroX-=65536;

                    //                if(abs(newgyroX-rawgyroX)>100)
                    //                {
                    //                  if(newgyroX>240&&newgyroX<256)
                    //                  {
                    //                    newgyroX-=256;
                    //                   }
                    //                   if(newgyroX<-240&&newgyroX>=-256)
                    //                  {
                    //                    newgyroX+=256;
                    //                   }
                    //                  }
                    if((abs(newgyroX)<500)&&(rawgyro[1]!=0))//(abs(newgyroX)<256)||(abs(newgyroX-rawgyroX)<100))
                    {
                        rawgyroX = newgyroX;
                        gyroX = rawgyroX/16.384;
                        sumGyroX+=gyroX;
                        countGyroX++;
                        if(countGyroX>=10000)
                        {
                            biasGyroX += 0.1*(sumGyroX/countGyroX-biasGyroX);
                            countGyroX=0;
                            sumGyroX = 0;
                            reportDebug("ac ",biasGyroX);
                        }
                        gyroX-=biasGyroX;
                        //                        Serial.print(gyroX);
                        //                        Serial.print(' ');
                        //                        Serial.print(stim_data.y_rate);
                        //////                        Serial.print(' ');
                        //////                        Serial.print(-10);
                        //////                        Serial.print(' ');
                        //////                        Serial.print(10);
                        //                        Serial.print('\n');
                    }

                    //                  Serial.print(newgyroX);
                    //                  Serial.print(' ');
                    //                Serial.println(gyroX);
                }

            }
            if(gyroByteIndex<15)
                rawgyro[gyroByteIndex] = databyte;
            gyroByteIndex++;

        }
        lastbyteGyro = databyte;

    }

}
double oldSpeeddpsH = 0;

void CGimbalController::outputSpeedH(double speeddps)//speed in degrees per sec
{

    if(ct11>0){
        hPulseBuff = h_ppr/120.0*CONTROL_TIME_STAMP;
    }
    else if(ct12>0){
        hPulseBuff = -h_ppr/120.0*CONTROL_TIME_STAMP;
    }
    else{
        double h_speed_pps = speeddps/360.0*h_ppr;
        hPulseBuff = (h_speed_pps*CONTROL_TIME_STAMP*2.0);//
        int maxBuf=h_ppr/4;
        if(hPulseBuff > maxBuf )hPulseBuff = maxBuf;
        if(hPulseBuff < -maxBuf)hPulseBuff = -maxBuf;
    }
    if(hPulseBuff==0)h_freq_devider = h_ppr*1000;
    else
    {
        h_freq_devider=CONTROL_TIME_STAMP*(float)MOTOR_PULSE_CLOCK/abs(hPulseBuff);
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

        digitalWriteFast(PD1, dir);
    }
}
double oldSpeeddpsV = 0;
void CGimbalController::outputSpeedV(double speeddps)//speed in degrees per sec
{

    if(ct21>0){
        vPulseBuff=v_ppr/120.0*CONTROL_TIME_STAMP;
    }
    else if(ct22>0){
        vPulseBuff=-v_ppr/120.0*CONTROL_TIME_STAMP;
    }
    else{
        double speed_pps = speeddps/360.0*v_ppr;
        vPulseBuff = (speed_pps*CONTROL_TIME_STAMP*2.0);//
        int maxBuf=v_ppr/4;
        if(vPulseBuff > maxBuf )vPulseBuff = maxBuf;
        if(vPulseBuff < -maxBuf)vPulseBuff = -maxBuf;
    }
    if(vPulseBuff==0)v_freq_devider = v_ppr*1000;
    else
    {
        v_freq_devider=CONTROL_TIME_STAMP*(float)MOTOR_PULSE_CLOCK/abs(vPulseBuff);
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
        digitalWriteFast(PD2, dir);
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
