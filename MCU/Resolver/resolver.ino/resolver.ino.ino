#include <SPI.h>
 
 const int AD2S1210_SAMPLE = 2;
 const int AD2S1210_SCK    = 1;   // Serial clock output
 #define _WR 10
 #define RESET 9
 uint16_t posn,poso;
 
 #define SAMPLE_H digitalWrite(AD2S1210_SAMPLE, HIGH)
 #define SAMPLE_L digitalWrite(AD2S1210_SAMPLE, LOW)
 #define SCLK_H digitalWrite(AD2S1210_SCK, HIGH)
 #define SCLK_L digitalWrite(AD2S1210_SCK, LOW)
 #define NM 5
 SPISettings settingsA(400000, MSBFIRST, SPI_MODE2);
 
 void setup() {
   Serial.begin(230400);
   pinMode (10, OUTPUT);
   pinMode (RESET, OUTPUT);
    pinMode (2, OUTPUT);
   pinMode (NM, INPUT);
   SPI.begin();
   digitalWrite(RESET,HIGH);
 }
 
 void loop() {
   
digitalWrite(10,LOW);
digitalWrite(2, LOW);
delay(10);
poso=posn;
   posn=READ_Position();
   int diff = posn-poso;
   digitalWrite(2, HIGH);
   digitalWrite(10,HIGH);
  //  if(digitalRead(NM))Serial.println(millis());
//  delay(1);
  //  delayMicroseconds(20);
    Serial.print("$RS1,"); 
   Serial.print(posn);
   Serial.print(",");
   Serial.print((posn>>8)+(posn&0xff));
   Serial.print("#\n");
 }
 
 uint16_t READ_Position(void)//read position
 {
   uint16_t position;
   
  //  delay(2);
   
  //  delay(2);

// SPIRead(0x78);
// SPIRead(0x78);
// delay(1);
uint8_t addr = 0x80;
   uint8_t bt1 =SPIRead(addr);
  //  Serial.print("1: "); 
  //  Serial.print(position);
   position=bt1<<9;
   uint16_t bt2 =SPIRead(addr);
  //  position=position>>1;
   position|=(bt2<<1)+(bt1>>7);

  //  position=SPIRead(addr);
  //  Serial.print("\t3: "); 
  //  Serial.print(position);
  //  position=SPIRead(addr);
  //  Serial.print("\t4: "); 
  //  Serial.println(position);
  //  position=SPIRead(0x91);
  //  position<<=8;
  //  position|=SPIRead(0x81);
   
   
   return position;
 }
 uint8_t SPIRead(const byte Reg) {


  uint8_t res = 0;

  // SPI.transfer(Reg);
  // digitalWrite(_WR, HIGH);


  // digitalWrite(_WR, LOW);
  res = SPI.transfer(Reg);
  // digitalWrite(_WR, HIGH);

  // setMode(NORMAL_VELOCTY);

  // Serial.print(F("\t Bin val: 0B")); Serial.println(res, BIN);
  // Serial.print(F("\t Hex val: 0X")); Serial.println(res, HEX);
  // Serial.print(F("\t Dec val: "));   Serial.println(res);
  
// 
  return res;

}