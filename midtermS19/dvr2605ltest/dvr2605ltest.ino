/********************** 

This worked for haptic driver alone.

**********************/

#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

int counter = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("DRV2605 Audio responsive test");
  drv.begin();


  drv.setMode(DRV2605_MODE_AUDIOVIBE);

  // ac coupled input, puts in 0.9V bias
  drv.writeRegister8(DRV2605_REG_CONTROL1, 0x20);  
 
  // analog input
  drv.writeRegister8(DRV2605_REG_CONTROL3, 0xA3);  
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}


void loop() {

  // 0-10 diff pulses
  analogWrite(9, counter);
  delay(2000);
  counter++;
  if(counter > 11){
    counter = 0;
  }
  Serial.println(counter);
  
}
