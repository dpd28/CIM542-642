/********************

THIS IS WORKING!!!! Woohoo!

*********************/


#include <Wire.h>
#include <Adafruit_DRV2605.h>

Adafruit_DRV2605 drv;

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

// haptic Output
int outputVibe = 0; // 

void setup() {
   Serial.begin(9600);
   Serial.println("DRV2605 Audio responsive test");
   drv.begin();
   
   drv.setMode(DRV2605_MODE_AUDIOVIBE);
   // ac coupled input, puts in 0.9V bias
   drv.writeRegister8(DRV2605_REG_CONTROL1, 0x20);  
   
   // analog input
   drv.writeRegister8(DRV2605_REG_CONTROL3, 0xA3);

   pinMode(9, OUTPUT); // Analog output from audio to haptic vibration

}

void loop() {

   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0); // -------  A0 analog input from audio sensor --------
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

   float soundOutput = map(volts, 0, 3.22, 1, 10); // first is audio, second is haptic changed from int soundOutput

    if (soundOutput <= 1){
      soundOutput = 0;
      }
    
    
    analogWrite(9, soundOutput);    // change the analog output values. Output pin and output value
    
    Serial.print("Volts: ");
    Serial.print(volts);
    Serial.print("\t soundOutPut: ");
    Serial.print(soundOutput);
    Serial.print("\t outputVibe: ");
    Serial.println(outputVibe);

 
    //delay(2000); // wait 2 seconds before the next loop begins

} // close loop - DO NOT DELETE!
