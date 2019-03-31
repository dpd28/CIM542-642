#include <Wire.h>
/* OK, This version definitely does not work.
 *  DO NOT USE
 * 
 * 
 */
 
 /#include <Adafruit_DRV2605.h>

Adafruit_DRV2605 drv;

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

// haptic Output
// int outputVibe = 0; // trying again at 9:25am

int outputVibe = 9; // trying this one -- def does not work

// reading of audio input is A0


void setup() {
   Serial.begin(9600);
   Serial.println("DRV2605 Audio responsive test");
   drv.begin();
   
   drv.setMode(DRV2605_MODE_AUDIOVIBE);
   // ac coupled input, puts in 0.9V bias
   drv.writeRegister8(DRV2605_REG_CONTROL1, 0x20);  
   
   // analog input
   drv.writeRegister8(DRV2605_REG_CONTROL3, 0xA3);

 //  pinMode(9, OUTPUT); // Analog output from audio to haptic vibration 1st attempt ------
   
   // Serial.begin(9600); - Don't think I need this aagin

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


   // max is 3.22
   // scale one sensor value and convert to another range. declare min and max values sensor and output min/max
   // pulse width modulation PWM
   
   int soundOutput = map(volts, 0, 3.22, 0, 10);
    
    Serial.print("Volts: ");
    Serial.print(volts);

    // output vibrate
    analogWrite(9, HIGH);
    Serial.println("\t outputVibe: ");
    Serial.print(outputVibe);

 
    delay(2000); // wait 2 seconds before the next loop begins

// ------- DELETE THIS WHEN YOU ARE FINISHED --------    
// else { < 7 } // add if less than 7 what happens. no decimals!
// analogWrite(outputVibe, 3.22);
// counter++;
//   if(counter > 11){
//    counter = 0;
//    }
//    Serial.println(counter);
    
} // close loop - DO NOT DELETE!
