# CIM642 Final Project

My final project for physical computing isn't anything new but for me, this was a project that is meaningful and tested my abilities.

More background about this project [is here](https://github.com/dpd28/CIM542-642/tree/master/midtermS19) as this is an extension of my midterm project.

## What's New?

### The Ardunio FFT library
This made my head hurt when reading through documentation about Fournier Frequency Transformation but the reason for using this library is to help translate the music through the microphone into different vibrations; meaning: reflect the variations and range of musical intonation.

![FFT Lesson in PWM](https://github.com/dpd28/CIM542-642/raw/master/images/FFT_IMG_8050.JPG)

### The GemmaM0
This is a small, lightweight microcontroller; one I wanted to use because I wanted to make this project into a wearable. For audio translation, the Uno is slower and the size is too clunky to use in a wearable project.

### Leather Encasement

In the midterm version, I used a small box as the encasement. Because the goal was to make this wearable — attractive, lightweight, portable — I focused on making a wristband. I looked to jewelry design for inspiration and stumbled upon Adafruit's design for their [meditation bracelet](https://learn.adafruit.com/buzzing-mindfulness-bracelet/overview). The design is quite functional given the following:

* The wearer needs access to the on/off switch
* Construction requires soldering after the microcontroller is encased.

![Sketches](https://github.com/dpd28/CIM542-642/raw/master/images/Wrist-Band-v2-IMG_8053.JPG)
![Paper test v1](https://github.com/dpd28/CIM542-642/raw/master/images/Wrist-Band-v3-Paper-IMG_8380.JPG)
![Paper test v1 Cricut](https://github.com/dpd28/CIM542-642/raw/master/images/Wrist-Band-v3-Paper-IMG_8378.JPG)
![Paper test v2](https://github.com/dpd28/CIM542-642/raw/master/images/Wrist-Band-v4-Paper-IMG_8387.JPG)
![Leather tough v1](https://github.com/dpd28/CIM542-642/raw/master/images/Wrist-Band-Leather-IMG_8433.JPG)
![Softer leather](https://github.com/dpd28/CIM542-642/raw/master/images/LeatherBlack_circuit_IMG_8519.JPG)
![Red leather xacto](https://github.com/dpd28/CIM542-642/raw/master/images/LeatherRed_circuit_IMG_8549.JPG)

![Snaps](https://github.com/dpd28/CIM542-642/raw/master/images/Snap01_IMG_8587.JPG)
![Snaps 2](https://github.com/dpd28/CIM542-642/raw/master/images/Snap02_IMG_8590.JPG)
![Snap ring random](https://github.com/dpd28/CIM542-642/raw/master/images/Snap03_IMG_8595.JPG)

**What I modified** I modified the design by using different colors of leather and adjusted the shape of the interior opening. It's a small adjustment but I experimented with several shapes.

This was also a test of using different weights of leather and the Cricut.

## Challenges
**Disoriented**: An unfamiliar microcontroller made me feel turned around so I had to map it out on paper.

**Fried GemmaM0**: I think I fried the microcontroller as I was refining the code. _Amazing_. This was a lesson to have a backup microcontroller on hand. Still, I used the Uno to keep testing. I gotta say, being able to _know_ to do that was a relief. Panic diverted.

(*Update: It turns out the GemmaM0 was not fried but there was some kind of short. This, and the code I wrote is messed up. At the moment I don't understand what I did that worked on the Uno but not the GemmaM0. To be investigated.())

![Arduino Uno backup](https://github.com/dpd28/CIM542-642/raw/master/images/IMG_8645.JPG)

![Testing code](https://github.com/dpd28/CIM542-642/raw/master/images/Mapping_IMG_8643.JPG)

* Leather and the Cricut: The softer the leather, the greater the fuzzy explosion. Here are a few tips:

* Taping down all sides of the leather on the cutting board is needed otherwise expect to jam up the Cricut.

**Strike a balance in the type of leather used and the weight or thickness**. The softer leather is of course more pleasant to touch but it is much more difficult to work with, especially if using the Cricut to make cuts. The stiffer the leather, the easier it is to cut using the Cricut but it isn't as nice on the skin and is you lose flexibility.
* Prepare to use the X-acto knife.

**Setting up the GemmaM0**: Be sure to read the documentation for the microcontroller. Turns out, the GemmaM0 works out of the box with Circuit Python but to use with Arduino, various installations need to be made before the GemmaM0 will work properly with Arduino.

## Brilliant

My professor, Zeven, helped create this beauty. I don't remember what it is called but it definitely stabilized the entire circuit. I was having trouble with the wires falling off of the solder or breaking. He suggested I hot glue the area with the solder and that worked brilliantly.

![Stable circuit](https://github.com/dpd28/CIM542-642/raw/master/images/compact_circuit_IMG_8760.jpg)

## Final Show!

The End of Year show was SO MUCH FUN. I wish I could have just spent time trying out everything my fellow classmates made. Hoping to link to more pictures.

![Detail of final project](https://github.com/dpd28/CIM542-642/raw/master/images/Gemma_Vibe_construction_IMG_8762.jpg)

This was probably the most difficult part of putting the final piece together. I used nuts and screws to connect the wires from the input to the GemmaM0. Tiny screws, tiny exposed pieces of wire; lots of frustration. BUT, I did it. Yay, me.

![Finished uploading code](https://github.com/dpd28/CIM542-642/raw/master/images/Gemma_Vibe_Final_IMG_8764.jpg)

![Testing](https://github.com/dpd28/CIM542-642/raw/master/images/gemmavibe-finalshow2019.800px.jpg)

![Trying out Gemma Vibe](https://github.com/dpd28/CIM542-642/raw/master/images/gemmaM0-audio-Vibe-800px.jpg)

The code is [here](https://github.com/dpd28/CIM542-642/blob/master/dpdFinal/FFT_Haptic/FFT_Haptic.ino) and below:


~~~~
/*

  Example of use of the FFT libray to compute FFT for a signal sampled through the ADC.
      Copyright (C) 2018 Enrique Condés and Ragnar Ranøyen Homb

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "arduinoFFT.h"

arduinoFFT FFT = arduinoFFT(); /* Create FFT object */

// IN PIN - Audio - is A1
// OUT PIN - Vibrate - is 6 or Gemma A0

double cur;



/*
  These values can be changed in order to evaluate the functions
*/
#define CHANNEL A1
const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const double samplingFrequency = 1000; //Hz, must be less than 10000 due to ADC

unsigned int sampling_period_us;
unsigned long microseconds;

/*
  These are the input and output vectors
  Input vectors receive computed results from FFT
*/
double vReal[samples];
double vImag[samples];

#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03

//#define Serial SerialUSB


#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)
// Required for Serial on Zero based boards
#define Serial SERIAL_PORT_USBVIRTUAL
#endif

void setup()
{
  sampling_period_us = round(1000000 * (1.0 / samplingFrequency));
  Serial.begin(115200);
 // while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
 // }
  Serial.println("Ready");

  pinMode(1, OUTPUT);
}

void loop()
{
  /*SAMPLING*/
  for (int i = 0; i < samples; i++)
  {
    microseconds = micros();    //Overflows after around 70 minutes!

    vReal[i] = analogRead(CHANNEL);
    vImag[i] = 0;
    while (micros() < (microseconds + sampling_period_us)) {
      //empty loop
    }
  }
  /* Print the results of the sampling according to time */
  //  Serial.println("Data:");
  //  PrintVector(vReal, samples, SCL_TIME);
  // FFT.Windowing(vReal, samples, FFT_WIN_TYP_HAMMING, FFT_FORWARD);	/* Weigh data */
  //  Serial.println("Weighed data:");
  //  PrintVector(vReal, samples, SCL_TIME);
  FFT.Compute(vReal, vImag, samples, FFT_FORWARD); /* Compute FFT */
  //  Serial.println("Computed Real values:");
  //  PrintVector(vReal, samples, SCL_INDEX);
  //  Serial.println("Computed Imaginary values:");
  //  PrintVector(vImag, samples, SCL_INDEX);
  FFT.ComplexToMagnitude(vReal, vImag, samples); /* Compute magnitudes */
  // Serial.println("Computed magnitudes:");
  PrintVector(vReal, (samples >> 1), SCL_FREQUENCY);
  // double x = FFT.MajorPeak(vReal, samples, samplingFrequency);
  // Serial.println(x, 6); //Print out what frequency is the most dominant.
  // while(1); /* Run Once */
  // delay(2000); /* Repeat after delay */
}

void PrintVector(double *vData, uint16_t bufferSize, uint8_t scaleType) {
  for (uint16_t i = 0; i < bufferSize; i++) {
    double abscissa;
    /* Print abscissa value */
    switch (scaleType)
    {
      case SCL_INDEX:
        abscissa = (i * 1.0);
        break;
      case SCL_TIME:
        abscissa = ((i * 1.0) / samplingFrequency);
        break;
      case SCL_FREQUENCY:
        abscissa = ((i * 1.0 * samplingFrequency) / samples);
        break;
    }

    //    Serial.print("VDATA: ");
    //      Serial.println(vData[i], 4);
    //      Serial.print(" ");

    //   if (vData[i] > 7 && vData[i] < 50) { //  low, mid, high values 1024 is top - abscissa > 400 && abscissa < 500

    if (abscissa > 400 && abscissa < 500) {
      if (scaleType == SCL_FREQUENCY) {
        if (vData[i] > 300) {
          cur = map(vData[i], 300, 1023, 0, 255);
          analogWrite(1, cur);
        }
      }

    }

  }
}

~~~~

## If I had more time …
**Encasement design**: I really would have liked to explore this more and experiment with materials like metals to combine with the leather. This experience actually renewed my interest in jewelry design. Interesting. I think something 3D printed in combination with metal on each side plus a stronger leather would be an interesting combo. Still, I'd have to think/plan more on the design to maintain access to the on/off switch. The other thought is something made entirely out of metal or wiring; something more futuristic / modern. Hmm…

**Add mini lights**: This may still be possible. I have a [Neopixel jewel](https://www.adafruit.com/product/2226?gclid=EAIaIQobChMIv5Cx6MLr4QIVjRyGCh2iXAshEAAYAiAAEgJY6fD_BwE) that could provide an additional sensory experience of music. I read that haptics in combination with visuals can be a more powerful experience.

**Add more vibrating motor discs**: I'm not sure if this would be too much or more helpful. It would be nice to explore and strike a balance.

**Refine the code**: I'm sure there are ways to refine the code (mapping pwm) more to cover the full range of frequencies and I need to study more to fully comprehend what is happening.
