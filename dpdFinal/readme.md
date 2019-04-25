# CIM642 Final Project

My final project for physical computing isn't anything new but for me, this was a project that is meaningful and tested my abilities.

More background about this project is here as this is an extension of my midterm project.

## What's New?

### The Ardunio FFT library
This made my head hurt when reading through documentation about Fournier Frequency Transformation but the reason for using this library is to help translate the music through the microphone into different vibrations; meaning: reflect the variations and range of musical intonation.

### The GemmaM0
This is a small, lightweight microcontroller; one I wanted to use because I wanted to make this project into a wearable. For audio translation, the Uno is slower and the size is too clunky to use in a wearable project.

### Leather Encasement
![]()
In the midterm version, I used a small box as the encasement. Because the goal was to make this wearable — attractive, lightweight, portable — I focused on making a wristband. I looked to jewelry design for inspiration and stumbled upon Adafruit's design for their [meditation bracelet](https://learn.adafruit.com/buzzing-mindfulness-bracelet/overview). The design is quite functional given the following:

* The wearer needs access to the on/off switch
* Construction requires soldering after the microcontroller is encased.

*What I modified* I modified the design by using different colors of leather and adjusted the shape of the interior opening. It's a small adjustment but I experimented with several shapes.

This was also a test of using different weights of leather and the Cricut.

## Challenges
Where do I start?

*Disoriented*: An unfamiliar microcontroller made me feel turned around so I had to map it out on paper.

*Fried GemmaM0*: I think I fried the microcontroller as I was refining the code. _Amazing_. This was a lesson to have a backup microcontroller on hand. Still, I used the Uno to keep testing. I gotta say, being able to _know_ to do that was a relief. Panic diverted.

*Leather and the Cricut*: Holy Hannah. The softer the leather, the greater the fuzzy explosion. Here are a few tips:

* Make sure you tape down all sides of the leather on the cutting board; otherwise expect to jam up the Cricut.

* Strike a balance in the type of leather used and the weight or thickness. The softer leather is of course more pleasant to touch but it is much more difficult to work with, especially if using the Cricut to make cuts. The stiffer the leather, the easier it is to cut using the Cricut but it isn't as nice on the skin and is you lose flexibility.
* Prepare to use the X-acto knife.

*Setting up the GemmaM0*: Be sure to read the documentation for the microcontroller. Turns out, the GemmaM0 works out of the box with Circuit Python but to use with Arduino, various installations need to be made before the GemmaM0 will work properly with Arduino.   

## If I had more time …
*Encasement design*: I really would have liked to explore this more and experiment with materials like metals to combine with the leather. This experience actually renewed my interest in jewelry design. Interesting. I think something 3D printed in combination with metal on each side plus a stronger leather would be an interesting combo. Still, I'd have to think/plan more on the design to maintain access to the on/off switch. The other thought is something made entirely out of metal or wiring; something more futuristic / modern. Hmm…

*Add mini lights*: This may still be possible. I have a [Neopixel jewel](https://www.adafruit.com/product/2226?gclid=EAIaIQobChMIv5Cx6MLr4QIVjRyGCh2iXAshEAAYAiAAEgJY6fD_BwE) that could provide an additional sensory experience of music. I read that haptics in combination with visuals can be a more powerful experience.

*Add more vibrating motor discs*: I'm not sure if this would be too much or more helpful. It would be nice to explore and strike a balance.
