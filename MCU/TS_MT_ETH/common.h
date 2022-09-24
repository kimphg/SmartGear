
#ifndef COMMON
#define COMMON
#define S_STIM Serial1
#define S_MT Serial2
#define E_CONTROL Serial3

#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 7);



int com_mode;
void reportDebug(const char* msg)
{
//  //S_CONTROL.print("$MSG,");
//  //S_CONTROL.println(msg);
  E_CONTROL.print("$MSG,");
  E_CONTROL.println(msg);
  Serial.print("$MSG,");
  Serial.println(msg);
}
void reportDebug(const char* msg,float value)
{
  E_CONTROL.print("$MSG,");
  E_CONTROL.print(msg);
  E_CONTROL.print(":");
  E_CONTROL.println(value);
  Serial.print("$MSG,");
  Serial.print(msg);
  Serial.print(":");
  Serial.println(value);
}
void reportDebug(int value,int value2)
{

	E_CONTROL.write(value);
  E_CONTROL.write(value2);
//	Serial.write(value);
//	S_CONTROL.write(value);
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
