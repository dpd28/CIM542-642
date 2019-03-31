
/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
https://learn.adafruit.com/adafruit-microphone-amplifier-breakout/measuring-sound-levels

THIS WORKED FOR AUDIO ALONE
****************************************/
#include <Wire.h>
#include <Adafruit_DRV2605.h>

Adafruit_DRV2605 drv;

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

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

   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0); // A0
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
   Serial.print("Volts: ");
   Serial.print(volts);

   // max is 3.22
   // scale one sensor value and convert to another range. declare min and max values sensor and output min/max
   // pulse width modulation PWM
   
   int soundOutput = map(volts, 0, 3.22, 0, 10);
   // Test output 
   Serial.print("soundOutput: ");
   Serial.println(soundOutput);
//
//   // Begin haptic vibrations
//   // 0-10 diff pulses
//   // change the output values
//   analogWrite(9, counter);
//
////   Serial.print("Volts: ");
////   Serial.print(volts);
////   Serial.print(counter);
////   Serial.println("\t Counter: ");
//   
delay(1000);
//// counter++;
////   if(counter > 11){
////    counter = 0;
////    }
////    Serial.println(counter);
    
} // close loop - DO NOT DELETE!
