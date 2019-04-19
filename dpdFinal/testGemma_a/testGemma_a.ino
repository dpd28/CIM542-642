

#define MIC_PIN   A1  // Microphone is attached to this analog pin
#define HAP_PIN    A0  // Vibe Motor Disc is connected to this pin

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

// haptic Output
int VibeOut = 0; // 

void setup() {
  // put your setup code here, to run once:
  
  //   Serial.begin(9600); 

/***
Serial gives errors — why? SerialUSB … 
***/

     pinMode(A0, OUTPUT); // Analog output from audio to haptic vibration

}


void loop() {
  // put your main code here, to run repeatedly:

   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(A1); // -------  A1 analog input from audio sensor --------
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

   float soundOutput = map(volts, 0, 3.22, 1, 10); // testing … first is audio, second is haptic changed from int soundOutput

    if (soundOutput <= 1){
      soundOutput = 0;
      }
    
    
    analogWrite(A0, soundOutput);    // change the analog output values. Output pin and output value

/***
Serial gives errors — why?
***/

//    Serial.print("Volts: ");
//    Serial.print(volts);
//    Serial.print("\t soundOutPut: ");
//    Serial.print(soundOutput);
//   Serial.print("\t VibeOut: ");
//    Serial.println(VibeOut);

} // closes the loop - do not delete DEB
