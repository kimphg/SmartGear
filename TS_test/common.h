#ifndef COMMON
#define COMMON
#define S_STIM Serial2
//#define S_CONTROL Serial1
#define E_CONTROL Serial3
//#include <SoftwareSerial.h>
//SoftwareSerial E_CONTROL =  SoftwareSerial(15, 14);
//NewSoftSerial mySerial(14, 15);  
int com_mode;
void reportDebug(const char* msg)
{
//  //S_CONTROL.print("$MSG,");
//  //S_CONTROL.println(msg);
  E_CONTROL.print("$MSG,");
  E_CONTROL.println(msg);
//  Serial.print("$MSG,");
//  Serial.println(msg);
}
void reportDebug(int msgcount)
{
  //S_CONTROL.print("$MSG,");
  //S_CONTROL.println(msgcount);
//  E_CONTROL.print("$MSG,");
//  E_CONTROL.println(msgcount);
//  Serial.print("$MSG,");
//  Serial.println(msgcount);
}
void reportDebug(float fov)
{
  //S_CONTROL.print("$MSG,");
  //S_CONTROL.println(fov);
//  if(com_mode==3)E_CONTROL.print("$MSG,");
//  if(com_mode==3)E_CONTROL.println(fov);
//  Serial.print("$MSG,");
//  Serial.println(fov);
}
void mPrint(const char* msg)
{
  //S_CONTROL.print(msg);
  if(com_mode==3)E_CONTROL.print(msg);
//  Serial.print(msg);
}
void mPrint(float msg)
{
  //S_CONTROL.print(msg);
//  if(com_mode==3)E_CONTROL.print(msg);
//  Serial.print(msg);
}
void mPrint(int msg)
{
  //S_CONTROL.print(msg);
//  if(com_mode==3)E_CONTROL.print(msg);
//  Serial.print(msg);
}
void mPrint(double msg)
{
  //S_CONTROL.print(msg);
//  if(com_mode==3)E_CONTROL.print(msg);
//  Serial.print(msg);
}
//void reportStim(float h_speed,float v_speed, int count)
//{
//    //S_CONTROL.print("$STM,");
//    //S_CONTROL.print(h_speed);
//    //S_CONTROL.print(",");
//    //S_CONTROL.print(v_speed);
//    //S_CONTROL.print(",");
//    //S_CONTROL.print(count);
//    //S_CONTROL.print(",");
//    //S_CONTROL.print("\n");
//  }

#endif
