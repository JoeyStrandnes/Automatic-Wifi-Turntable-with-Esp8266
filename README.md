# Automatic-Wifi-Turntable-with-Esp8266
This is a simple ultra low cost automation for turntables using an Esp8266, Blynk and 28BYJ-48 stepper motor! It uses a mobile phone combined with an Esp to take a set number of photos per revolution.

## Getting Started

To get started with this turntable youll need the following

## Software
```
  - Arduino IDE
  - Blynk Library https://github.com/blynkkk/blynk-library/releases/tag/v0.4.8
  - AccelStepper Library http://www.airspayce.com/mikem/arduino/AccelStepper/index.html
  ```
  
## Hardware
```
  - Esp8266
  - 28Byj-48 Stepper Motor
  - Unipolar stepper motor driver (Or a bipolar one, you have to disconnet the red wire, in this example i used the ULN2003 driver)
  - 3.5 mm male headphone connetor with microphone pin (4-pin)
  - 600 Ω resistor
  - NPN transistor (BC547C)
  - Two screws and two nuts
  - Some cables
  - And a file or sand paper
```

## Schematic
```
Check the schematics folder for full scematics!

ESP8266 - Using a NodeMCU

---NodeMCU - Motor Driver Board---
    
   NodeMCU Pin: GND ---> GND
   NodeMCU Pin: VCC ---> +5V
   NodeMCU Pin: D0 ---> IN1
   NodeMCU Pin: D1 ---> IN2
   NodeMCU Pin: D2 ---> IN3
   NodeMCU Pin: D3 ---> IN4
 
---NodeMCU - Headphone - NPN---
  
   NodeMCU Pin: GND ---> Sleeve
   NodeMCU Pin: D6 ---> NPN Pin: 2 (Base)
   Ring2 (Mic/ Seccond contact from the top) ---> 600Ω ---> NPN Pin: 1 (Collector)
   NPN Pin: 3 (Emitter) ---> GND
   
---Motor Driver---
   
   Motor Driver Pin: GND ---> GND
   Motor Driver Pin: VCC ---> +5V
   Motor Driver Pin: ON ---> Short both "ON" pins with a jumper cable to activate the motor driver
   Motor Driver Pin: Plastic connector ---> Connect it to the motor 
   
```
## Setting up the code
```
Change the following lines:

  Line: 18 ---> Replace the text SSID with your network name
  Line: 19 ---> Replace the text paswd with your network password
  Line: 20 ---> Replace the text Auth with your auth token from Blynk (More details later on in the article)
  
---Optional---

   Depending on which board you are using you might need to change the pins used
   Line: 9-12 ---> Change the pins to the pins you’d rather use (Motor driver pins)
   Line: 28 ---> Change the pin to the pin you’d rather use (Used to take the picture)
```
## Setting up the mobile app
```
This is made possible thanks to the people over at Blynk!
If you are using Android download this app from the Play store: http://j.mp/blynk_Android
If you are using IOS download the app from the Apple store: http://j.mp/blynk_iOS

Now to use the app with this projekt your going to have to clone my project. To do so go to the schematics folder in my GitHub repo and open the file called Turntable - APP.jpg and scann the QR code. or open this link http://tinyurl.com/ybspq849

 And that should be it!
```
## Finishing up the project
```
To finalize the project youll need something to contain it, Ive designed 3 files to print on a 3D-printer. The turntable, a top lid and a bottom lid to the container.

Print all these files in whatever material you want it doesn’t matter, however they are designed with very little tolerance to prevent play in the system so I recommend sanding the threads down a bit before fitting them for the first time. For more info check out my Thingyverse post (Link coming soon)

Screw everything together and its done!

Hope you enjoyed this project!
```
