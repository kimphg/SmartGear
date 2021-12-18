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
//byte L3G4200D_ADDRESS =0x6B;
byte L3G4200D_ADDRESS =0x69;
byte RawDatabuffer[17]; // Array of Bytes. Each byte in the array will hold one byte of data for MSB and LSB
float rawX, rawY, rawZ;
float Gyro_X,Gyro_Y,Gyro_Z;
float Acc_X, Acc_Y, Acc_Z, MagnX, MagnY, MagnZ;
float T_raw, Temp;
int led = LED_BUILTIN;
float a_sensitivityConst, m_sensitivityConst, T_Const;
byte outputBuffer[6];
float angle = 0;
//******************** Setup section **************************
void setup()
{
  Serial1.begin(250000);
  Serial.begin(115200);
  Wire.setSDA(20);
  Wire.setSCL(21);
  Wire.begin();
  GY89_Setup();
  outputBuffer[0]=0x7f;
  outputBuffer[1]=0x7f;
  outputBuffer[2]=0x03;
  pinMode(led, OUTPUT);
}
//********************* Main loop *******************************
int oldtime=0;
int count = 0;
int calibNumber = 1000;
byte oldbyte = 0;
int sumGyro=0;
int gyroCalib = 0;
void loop() {
  
  getGyro();
  if(oldbyte!=RawDatabuffer[6])
  {
    oldbyte=RawDatabuffer[6];
    int gyroz = RawDatabuffer[6]+RawDatabuffer[7]*256;
    if(gyroz>=32768)gyroz-=65536; 
    if(abs(gyroz)<600)
    {
      count++;
      sumGyro+=gyroz;
      if(count>calibNumber)
      {
        gyroCalib = sumGyro/count;
        count = 0;
        sumGyro = 0;
        if(calibNumber<16000)calibNumber*=2;
      }
    }
    gyroz-=gyroCalib;
    short output = (short)gyroz;
    outputBuffer[3] = output>>8;
    outputBuffer[4] = output&0xff;
    
    
    outputBuffer[5]=outputBuffer[3]^outputBuffer[4];
    Serial.println(output);
    digitalWrite(led,HIGH);
    while (Serial1.available())
    {
      Serial1.read();
      delayMicroseconds(50);
    }
    Serial1.write(outputBuffer,6);
    //delay(10);
  }
  else digitalWrite(led,LOW);
  
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
//  SetSensor(I2C_Addr_LSM303D, CTRL0_LSM303D, 0b00000000); // CTRL0(1Fh):
//  SetSensor(I2C_Addr_LSM303D, CTRL1_LSM303D, 0b01010111); // CTRL1(20h): Register: acceleration data-rate is 0001 i.e. 50 Hz and all axis are enabled with continous update
//  SetSensor(I2C_Addr_LSM303D, CTRL2_LSM303D, 0b00011000); // CTRL2(21h): Acceleration Anti-alias filter, full-scale selection(+- 8g), self-test, SPI mode selection
//  SetSensor(I2C_Addr_LSM303D, CTRL3_LSM303D, 0b00000000); // CTRL3(22h):
//  SetSensor(I2C_Addr_LSM303D, CTRL4_LSM303D, 0b00000000); // CTRL4(23h):
//  SetSensor(I2C_Addr_LSM303D, CTRL5_LSM303D, 0b11110000); // CTRL5(24h): Magnetometer config
//  SetSensor(I2C_Addr_LSM303D, CTRL6_LSM303D, 0b00100000); // CTRL6(25h): Magnetometer: +-4 gauss magnetic full-scale
//  SetSensor(I2C_Addr_LSM303D, CTRL7_LSM303D, 0b10000000); // CTRL7(26h): MD[1:0] == [0:0] i.e. continuous conversion mode;; High-Pass Filter:Normal mode

  // Sensitivity settings
//  getSensConst('a', 8);
//  getSensConst('m', 4);
//  getSensConst('T', 0);
   delay(100);
  SetSensor(L3G4200D_ADDRESS ,0x20 ,0x8F ); // CTRL_REG1   400Hz ODR, 20hz filter, run!
//  SetSensor(L3G4200D_ADDRESS ,0x20 ,0xCF ); // CTRL_REG1   800Hz ODR, 30hz filter, run!
  delay(5);
  SetSensor(L3G4200D_ADDRESS ,0x24 ,0x02 ); // CTRL_REG5   low pass filter enable
  delay(5);
//  SetSensor(L3G4200D_ADDRESS ,0x23 ,0x30); // CTRL_REG4 Select 2000dps
  SetSensor(L3G4200D_ADDRESS ,0x23 ,0x90); // CTRL_REG4 Select 2000dps BDU=1
}
//float getSensConst(char SensType, int FullScaleSens)
//{
//  if (SensType == 'a') // a for accelerometer
//  {
//    if (FullScaleSens == 2)// +-2g
//    {
//      a_sensitivityConst = 0.061; // 0.061 mg/LSB
//    }
//    else if (FullScaleSens == 4)
//    {
//      a_sensitivityConst = 0.122;
//    }
//    else if (FullScaleSens == 6)
//    {
//      a_sensitivityConst = 0.183;
//    }
//    else if (FullScaleSens == 8)
//    {
//      a_sensitivityConst = 0.244;
//    }
//    else if (FullScaleSens == 16)
//    {
//      a_sensitivityConst = 0.732;
//    }
//  }
//  else if (SensType == 'm')// m for magnetometer
//  {
//    if (FullScaleSens == 2)
//    {
//      m_sensitivityConst = 0.080; // 0.061 mg/LSB
//    }
//    else if (FullScaleSens == 4)
//    {
//      m_sensitivityConst = 0.160; // 0.061 mg/LSB
//    }
//    else if (FullScaleSens == 8)
//    {
//      m_sensitivityConst = 0.320; // 0.061 mg/LSB
//    }
//    else if (FullScaleSens == 12)
//    {
//      m_sensitivityConst = 0.479; // 0.061 mg/LSB
//    }
//  }
//  else if (SensType == 'T' && FullScaleSens == 0)
//  {
//    T_Const = 8; // 8 LSB/C°
//  }
//  else
//  {
//    a_sensitivityConst = 0.061;
//    m_sensitivityConst = 0.160;
//    T_Const = 8;
//  }
//  return 0;
//}
