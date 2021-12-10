/* Created by zmn33: This program code reads the 3-Axis Accelerometer, Magnetometer
,Temperature Sensor measurements from GY-89 breakout board */

#include <Wire.h>

#define CTRL0_LSM303D 0x1F
#define CTRL1_LSM303D 0x20
#define CTRL2_LSM303D 0x21
#define CTRL3_LSM303D 0x22
#define CTRL4_LSM303D 0x23
#define CTRL5_LSM303D 0x24
#define CTRL6_LSM303D 0x25
#define CTRL7_LSM303D 0x26

#define RegMagStart 0x08
#define RegAccStart 0x28
#define RegTempStart 0x05


byte I2C_Addr_LSM303D = 0x1D;
byte L3G4200D_ADDRESS =0x6B;
byte RawDatabuffer[17]; // Array of Bytes. Each byte in the array will hold one byte of data for MSB and LSB
float rawX, rawY, rawZ;
float Gyro_X,Gyro_Y,Gyro_Z;
float Acc_X, Acc_Y, Acc_Z, MagnX, MagnY, MagnZ;
float T_raw, Temp;

float a_sensitivityConst, m_sensitivityConst, T_Const;
//******************** Setup section **************************
void setup()
{
  Serial1.begin(460800);
//  Serial.begin(115200);
  Wire.begin();
  GY89_Setup();
  RawDatabuffer[0]=0x7f;
  RawDatabuffer[1]=0x7f;
}
//********************* Main loop *******************************
int oldtime=0;
int count = 0;
void loop() {
  int newtime = millis();
//  Serial.println(newtime-oldtime);
if(newtime-oldtime<2&&newtime-oldtime>0)return;
  oldtime = newtime;
//  Serial.print(",  ");
  // put your main code here, to run repeatedly:
  
//  getMag();
  count++;
  getGyro();
  if(count%10==0){
  getTemp();
  getAcc();
  }
  RawDatabuffer[16]=0;
  for (int i=2;i<16;i++)
  {
    RawDatabuffer[16]^=RawDatabuffer[i];
//    Serial.print(RawDatabuffer[i]);
//    Serial.print(" ");
    }
//      float gyrox = RawDatabuffer[2]+RawDatabuffer[3]*256;
//if(gyrox>=32768)gyrox-=65536;
// Serial.println(gyrox);
//  Serial.print("\n");
  Serial1.write(RawDatabuffer,17);
//delay(10);
}
//*************************************************************

void ReadBytes(byte I2C_DevAddress, byte FromRegAddress, byte NrBytes, int storageId)
{
  Wire.beginTransmission(I2C_DevAddress);
  Wire.write(FromRegAddress | (1 << 7));// inserting 1 to MSB of the register to indicate reading, otherwise it is zero and means writing
  Wire.endTransmission(false);
  Wire.requestFrom(I2C_DevAddress, (byte)NrBytes, true);
  for (int i = 0; i < NrBytes; i++)
  {
    RawDatabuffer[i+storageId] = Wire.read();
  }
  return;
}
//********************************************

void getAcc()
{
  ReadBytes(I2C_Addr_LSM303D, RegAccStart, 6,8); 
}

void getTemp()
{

  ReadBytes(I2C_Addr_LSM303D, RegTempStart, 2,14);

}
void getGyro()
{
  ReadBytes(L3G4200D_ADDRESS, 0x80|0x28, 6,2); 

  }
void SetSensor(byte I2C_DevAddress, byte RegAddress, byte SetValBin)
{
  Wire.beginTransmission(I2C_DevAddress);
  Wire.write(RegAddress);             // CTRL7 Register: Selection mode for High-pass filter AHPM1 and AHPM0 10 and Magnetic Sensor
  Wire.write(SetValBin);       // Magnetic Sensor selection mode is continoues
  Wire.endTransmission(true);
}
void GY89_Setup()
{
  SetSensor(I2C_Addr_LSM303D, CTRL0_LSM303D, 0b00000000); // CTRL0(1Fh):
  SetSensor(I2C_Addr_LSM303D, CTRL1_LSM303D, 0b01010111); // CTRL1(20h): Register: acceleration data-rate is 0001 i.e. 50 Hz and all axis are enabled with continous update
  SetSensor(I2C_Addr_LSM303D, CTRL2_LSM303D, 0b00011000); // CTRL2(21h): Acceleration Anti-alias filter, full-scale selection(+- 8g), self-test, SPI mode selection
  SetSensor(I2C_Addr_LSM303D, CTRL3_LSM303D, 0b00000000); // CTRL3(22h):
  SetSensor(I2C_Addr_LSM303D, CTRL4_LSM303D, 0b00000000); // CTRL4(23h):
  SetSensor(I2C_Addr_LSM303D, CTRL5_LSM303D, 0b11110000); // CTRL5(24h): Magnetometer config
  SetSensor(I2C_Addr_LSM303D, CTRL6_LSM303D, 0b00100000); // CTRL6(25h): Magnetometer: +-4 gauss magnetic full-scale
  SetSensor(I2C_Addr_LSM303D, CTRL7_LSM303D, 0b10000000); // CTRL7(26h): MD[1:0] == [0:0] i.e. continuous conversion mode;; High-Pass Filter:Normal mode

  // Sensitivity settings
  getSensConst('a', 8);
  getSensConst('m', 4);
  getSensConst('T', 0);
   delay(100);
  SetSensor(L3G4200D_ADDRESS ,0x20 ,0x8F ); // CTRL_REG1   400Hz ODR, 20hz filter, run!
//  SetSensor(L3G4200D_ADDRESS ,0x20 ,0xCF ); // CTRL_REG1   800Hz ODR, 30hz filter, run!
  delay(5);
  SetSensor(L3G4200D_ADDRESS ,0x24 ,0x02 ); // CTRL_REG5   low pass filter enable
  delay(5);
//  SetSensor(L3G4200D_ADDRESS ,0x23 ,0x30); // CTRL_REG4 Select 2000dps
  SetSensor(L3G4200D_ADDRESS ,0x23 ,0xA0); // CTRL_REG4 Select 2000dps BDU=1
}
float getSensConst(char SensType, int FullScaleSens)
{
  if (SensType == 'a') // a for accelerometer
  {
    if (FullScaleSens == 2)// +-2g
    {
      a_sensitivityConst = 0.061; // 0.061 mg/LSB
    }
    else if (FullScaleSens == 4)
    {
      a_sensitivityConst = 0.122;
    }
    else if (FullScaleSens == 6)
    {
      a_sensitivityConst = 0.183;
    }
    else if (FullScaleSens == 8)
    {
      a_sensitivityConst = 0.244;
    }
    else if (FullScaleSens == 16)
    {
      a_sensitivityConst = 0.732;
    }
  }
  else if (SensType == 'm')// m for magnetometer
  {
    if (FullScaleSens == 2)
    {
      m_sensitivityConst = 0.080; // 0.061 mg/LSB
    }
    else if (FullScaleSens == 4)
    {
      m_sensitivityConst = 0.160; // 0.061 mg/LSB
    }
    else if (FullScaleSens == 8)
    {
      m_sensitivityConst = 0.320; // 0.061 mg/LSB
    }
    else if (FullScaleSens == 12)
    {
      m_sensitivityConst = 0.479; // 0.061 mg/LSB
    }
  }
  else if (SensType == 'T' && FullScaleSens == 0)
  {
    T_Const = 8; // 8 LSB/C°
  }
  else
  {
    a_sensitivityConst = 0.061;
    m_sensitivityConst = 0.160;
    T_Const = 8;
  }
}
