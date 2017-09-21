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
  - Some cables
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
   
   


