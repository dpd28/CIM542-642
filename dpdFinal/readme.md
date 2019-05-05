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

![Sketches](https://github.com/dpd28/CIM542-642/blob/master/images/Wrist-Band-v2-IMG_8053.JPG)
![Paper test v1](https://github.com/dpd28/CIM542-642/blob/master/images/Wrist-Band-v3-Paper-IMG_8380.JPG)
![Paper test v1 Cricut](https://github.com/dpd28/CIM542-642/blob/master/images/Wrist-Band-v3-Paper-IMG_8378.JPG)
![Paper test v2](https://github.com/dpd28/CIM542-642/blob/master/images/Wrist-Band-v4-Paper-IMG_8387.JPG)
![Leather tough v1](https://github.com/dpd28/CIM542-642/blob/master/images/Wrist-Band-Leather-IMG_8433.JPG)
![Softer leather](https://github.com/dpd28/CIM542-642/blob/master/images/LeatherBlack_circuit_IMG_8519.JPG)
![Red leather xacto](https://github.com/dpd28/CIM542-642/blob/master/images/LeatherRed_circuit_IMG_8549.JPG)

![Snaps](https://github.com/dpd28/CIM542-642/blob/master/images/Snap01_IMG_8587.JPG)
![Snaps 2](https://github.com/dpd28/CIM542-642/blob/master/images/Snap02_IMG_8590.JPG)
![Snap ring random](https://github.com/dpd28/CIM542-642/blob/master/images/Snap03_IMG_8595.JPG)

**What I modified** I modified the design by using different colors of leather and adjusted the shape of the interior opening. It's a small adjustment but I experimented with several shapes.

This was also a test of using different weights of leather and the Cricut.

## Challenges
**Disoriented**: An unfamiliar microcontroller made me feel turned around so I had to map it out on paper.

**Fried GemmaM0**: I think I fried the microcontroller as I was refining the code. _Amazing_. This was a lesson to have a backup microcontroller on hand. Still, I used the Uno to keep testing. I gotta say, being able to _know_ to do that was a relief. Panic diverted.

(*Update: It turns out the GemmaM0 was not fried but there was some kind of short. This, and the code I wrote is messed up. At the moment I don't understand what I did that worked on the Uno but not the GemmaM0. To be investigated.())

![Arduino Uno backup](https://github.com/dpd28/CIM542-642/blob/master/images/IMG_8645.JPG)

![Testing code](https://github.com/dpd28/CIM542-642/blob/master/images/Mapping_IMG_8643.JPG)

* Leather and the Cricut: The softer the leather, the greater the fuzzy explosion. Here are a few tips:

* Taping down all sides of the leather on the cutting board is needed otherwise expect to jam up the Cricut.

**Strike a balance in the type of leather used and the weight or thickness**. The softer leather is of course more pleasant to touch but it is much more difficult to work with, especially if using the Cricut to make cuts. The stiffer the leather, the easier it is to cut using the Cricut but it isn't as nice on the skin and is you lose flexibility.
* Prepare to use the X-acto knife.

**Setting up the GemmaM0**: Be sure to read the documentation for the microcontroller. Turns out, the GemmaM0 works out of the box with Circuit Python but to use with Arduino, various installations need to be made before the GemmaM0 will work properly with Arduino.   

## If I had more time …
*Encasement design*: I really would have liked to explore this more and experiment with materials like metals to combine with the leather. This experience actually renewed my interest in jewelry design. Interesting. I think something 3D printed in combination with metal on each side plus a stronger leather would be an interesting combo. Still, I'd have to think/plan more on the design to maintain access to the on/off switch. The other thought is something made entirely out of metal or wiring; something more futuristic / modern. Hmm…

**Add mini lights**: This may still be possible. I have a [Neopixel jewel](https://www.adafruit.com/product/2226?gclid=EAIaIQobChMIv5Cx6MLr4QIVjRyGCh2iXAshEAAYAiAAEgJY6fD_BwE) that could provide an additional sensory experience of music. I read that haptics in combination with visuals can be a more powerful experience.

**Add more vibrating motor discs**: I'm not sure if this would be too much or more helpful. It would be nice to explore and strike a balance.
