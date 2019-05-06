**Midterm - Physical Computing**

# Feel the Music
**Briefly explain why did you want to make this project?**

## Why Make This Project?
I made this project with my dad in mind. He lost hearing in one ear due to a neroma. He has always loved music and as a kid wanted to be a symphony orchestra conductor. In his heart he really is a conductor even though he worked as a physician.

**Who are the stakeholders?**
I have a special place for people with "invisible" impairments or disabilities (which is PC?). The world is not designed for people who are outside "the norm" and as a designer I've become more attuned to trying to understand their needs.

* People who love music but have lost their hearing or their hearing isn't "normal".
* People who love the people who have lost their  hearing; wanting them to experience say a concert or a song together
* People who teach people with hearing loss. I think something like this could be used to teach language? Like a morse code communicator on the skin.

## Projects that Inspired Me
*Find 3 inspiring projects*

[Haptic Compass Belt](https://www.engadget.com/2009/02/09/haptic-compass-gives-you-sense-of-direction-not-style/)

[Sentiri Proximity Sensing Headband](https://www.engadget.com/2015/11/20/headband-detects-obstacles-and-guides-the-blind-haptically/)

[Music for your skin](https://www.pbs.org/wgbh/nova/article/haptic-hearing/)

[Haptic Chair](https://youtu.be/kRlqKcIJvDc)

**Code**
**How does your program work? (Explain your code)**

OK, so I still need to dive into what the code is doing specifically in the setup as I've never seen this before. But there must be some relationship with the library to set up the haptic driver into audio mode?

The sample variable is reading the audio input into Pin A0 and telling the arduino to establish a min and max value. The first part of the loop is determining value ranges.

Then the values are mapped to convert values from the input (audio) to output (haptic vibration) using PWM (pulse width modulation). For mapping, initially, an `int` variable was used but I was having issues with getting the vibrations to register the lower range of values. Enter: `float` variable types which allow for decimal points! I think this was helpful.

The values are converted and sent through Pin 9. So, in this case, if the soundOutput is less than or greater than 1 then basically do nothing. But if it is greater than 1 write to Pin 9 and vibrate.

### Reflection and Everything I Tried
**What worked/did not work?**

**The components/sensors**. Separately the sensors worked great with the sample code and even when I was tooling around with the different sketches. It was exciting. But *what didn't work so great* is tying them together — haptic drive with the vibration disc and the audio input (electret mic). It's like I'm trying to put two sentences together to make it flow well and I'm stuck on not knowing the words or how they connect one to the other; sometimes writing too much and overthinking it or … I don't know.

![haptic test circuit](https://github.com/dpd28/CIM542-642/raw/master/images/Haptic_Test_IMG_7322.jpg)

**A lot of the code**. I used a book that was recommended to really dive in and understand what we had done so far in the semester and break it down so I could practice and understand. The Make: Learn Electronics with Arduino is hands down the best book so far. I love how it breaks down the syntax in digestible chunks.

This book helped a TON.
![Arduino MAKE book](https://github.com/dpd28/CIM542-642/raw/master/images/09-Book_IMG_7679.jpg)

**Blew off the disc**. I think when I was trying out different capacitors, I blew off the vibration disc connection to the haptic driver! I was trying to figure out the range to adjust the mapping (pwm) and I think that's when it blew off. Geez.

![Busted haptic controller connection](https://github.com/dpd28/CIM542-642/raw/master/images/07-Broken_Haptic_IMG_7670.jpg)

#### Testing the distance sensor
This did not work at first using the [example sketch](https://www.arduino.cc/en/Tutorial/Ping) provided by Arduino. I'm not sure why and it could have been illness. Initially I thought it was a bad sensor but decided to try it again and [it worked with LEDs](https://youtu.be/jySApnWT1oo)!

![Distance sensor Test Circuit](https://github.com/dpd28/CIM542-642/raw/master/images/01-Dist-Led-Test-Overview-IMG_7335.jpg)

#### Setting up the haptic driver
[Playing around with the different wave forms](https://youtu.be/WMzVtQOsiHk) was fun. I tried making a tune but it isn't easy!

[This video](https://youtu.be/pgBHsXWS3rA) was when it was finally working with the audio input.

#### Research into Audio input to Vibration output
After some searching around the internet, I discovered in order to have the accuator vibrate as ambient music is playing, I need a Electret MAX4556 microcontroller and a 1UF capacitor which I don't think (at this time) is included in the starter Arduino kit.

(I bought the electret mic and various other components and parts … Adafruit is addictive.)

**If you had more time what would you change in your project?**
Ideally I would not have gotten the flu or whatever nasty virus I had. With some exploration in the Adafruit shop (hello, I should have gone there first instead of some robot website) I'd try to use the Gemma M0 or Flora from Adafruit which would allow greater integration with fabric and be lighter to wear on the wrist! I'm eager to explore this option more.

Oh if this were say for a little girl, I would add some fun mini-lights in a bracelet form. I'm wondering if there is a way to have them blink to the music and have the disc vibrate. I feel like just getting started keeps opening more ideas. I just wish I could focus one one thing like this class - lol.

Ideally there is a switch to turn the haptic device on and off but 1) I wasn't able to get the part delivered fast enough when I thought of it (illness) and 2) the whole things needs to be wearable so this is I guess a first working prototype.

But the idea is that the user can turn it on and off and then when audio or sound (input) reaches a certain level as defined in the code, the haptic vibrations are the output.

### Components
**What parts did you use?**
* [Parallax PING distance sensor](https://learn.parallax.com/tutorials/language/propeller-c/propeller-c-simple-devices/sense-distance-ping)
* Arduino Uno board
* Arduino breadboard
* Haptic Motor Controller (DRV2605L)
* Vibrating Mini Motor Disc
* 1UF Capacitor (actually used a smaller one and tried a few)
* Electret M4466 Microcontroller Microphone

### Which are your inputs/outputs
#### Interaction
**Explain how a user interacts with your input/output**

In its current iteration, it isn't very portable but after connecting it to the computer, the user would play music to activate the vibration disc and feel the various types of vibrations through their fingers.

**Create a layout for your interface**

*Not sure what this means … layout for interface?*

### Storyboard the interaction

![Flow Chart](https://github.com/dpd28/CIM542-642/raw/master/images/Audio-Vibe%20Flow.jpg)

### Explain how the project is used?**

**How does the user interact with the input**

In a future iteration, the user would be able to put the wearable device on their wrist and be able to turn the device off and on since without a switch, it would vibrate for every type of noise that falls within the threshold. I think the GemmaM0 actually has a switch but not sure if it is accessible by a person when encased. By placing on the wrist, people don't have to hold anything or deal with managing wires, etc. All they need to do is turn it on and then off to feel the vibrations of the music.

**Why did you decide to use that component?**

As mentioned before I started with the PING distance sensor but that wasn't the type of input I wanted to capture. My goal was to create a music listening device for people who cannot hear at all or have minimal hearing so I needed to have a component that would "capture" frequencies. After some Googling, I discovered the Electret mic.
**Explain how the input translates to the output**

So this device uses `analogRead` and `analogWrite` to function in addition to a library for the haptic controller. The analog functions allow for a range of averaged values compared to digital functions.

The Electret Mic amplifier (input), powered through the Arduino through pin 3.3v, changes the voltage through Pin A0 and translates back to the arduino to change the values to the haptic controller/vibration disc (output, powered through pin 5v) using the `map` function (min and max values). The converted values are sent through Pin 9 using pulse wave modulation (PWM). So the intensity of the vibration and when the vibration is triggered depends on the analog values received from the electret mic.

**Talk about what form factor/size your project would ideally be.**

Ideally this could be much smaller, lighter, and more fashionable for both men and women. I learned from Dr. Millet that the wrist and fingers are the most sensitive to haptic feedback. So, ideally this would be something a person could wear on their wrists to feel the vibrations along the underside of their wrists.

In terms of materials, fabric such as leather would be sturdy enough though it may not be as breathable for hot weather locations.

### Images and Videos

**Progress images**

![Making a mess](https://github.com/dpd28/CIM542-642/raw/master/images/01-WorkMess_IMG_7669.jpg)

![Encased begin](https://github.com/dpd28/CIM542-642/raw/master/images/02-Encase_02_Mess_IMG_7666.jpg)

![Working on the lid/cover](https://github.com/dpd28/CIM542-642/raw/master/images/03-White_Lid_Horiz_IMG_7671.jpg)

![Top view](https://github.com/dpd28/CIM542-642/raw/master/images/04-White_Horiz_Open_IMG_7672.jpg)

![From the side](https://github.com/dpd28/CIM542-642/raw/master/images/05-Inside_IMG_7674.jpg)

![Final 1st round encasement](https://github.com/dpd28/CIM542-642/raw/master/images/06-Gold_IMG_7677.jpg)

**Finished input and output**

![Finished Arduino and breadboard](https://github.com/dpd28/CIM542-642/raw/master/images/Works_03272019_IMG_7654.jpg)

![Close Up of breadboard in case](https://github.com/dpd28/CIM542-642/raw/master/images/Close-Up-Finished_IMG_7780.jpg)

**Finished Breadboard**

![Final breadboard](https://github.com/dpd28/CIM542-642/raw/master/images/08-CloseUp_IMG_7628.jpg)

![Finished looking into encasement](https://github.com/dpd28/CIM542-642/raw/master/images/Finsihed_Guts_IMG_7778.jpg)

## See the [final version on YouTube](https://youtu.be/uxcoEpMwsCQ_).
