//Created by Joey Makdesi

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
#define BLYNK_EXPERIMENTAL
#include <AccelStepper.h>

#define HALFSTEP 8

#define motorPin1  D0
#define motorPin2  D1
#define motorPin3  D2
#define motorPin4  D3

WidgetTerminal terminal(V1);
BLYNK_WRITE(V1);


char * ssid = "SSID"; //Network name
char * pass = "paswd"; //Password
char * auth = "Auth"; //Auth token

//Variables
int Speed;
int pics = 1;
int paus;
int counter;
int var = 1;
int snap = D6;

bool go = false;
bool Running = false;

int Move;

//Stepper motor pin configuration
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

//Custom delay funktion
void Blynk_Delay(int milli){
   int end_time = millis() + milli;
   while(millis() < end_time){
       Blynk.run();
       stepper1.run();
       yield();
   }
}

//Virtual button from Blynk app
BLYNK_WRITE(V2){
  int StartTurntable = param.asInt();

    //Blynk_Delay(5000);
    terminal.flush();

  if (StartTurntable == 1) {
    //Running = true;
    while(counter <= pics){
    paus = 4096/pics;
    Move = Move + paus;
    stepper1.moveTo(Move);
    
    //Take Picture
    Blynk_Delay(500);
    digitalWrite(snap, HIGH);
    Blynk_Delay(500);
    digitalWrite(snap, LOW);
    
    
    counter++;
    terminal.println(counter);
    Blynk_Delay(3000);

    
    }
  }
}



//Slider to control speed
BLYNK_WRITE(V4){
  int Speed = param.asInt();

  stepper1.setMaxSpeed(Speed * 10);
}


//Menu
BLYNK_WRITE(V0) {
  switch (param.asInt())
  {
    case 1: // Item 1
    pics = 50;
      break;
    case 2: // Item 2
    pics = 100;
      break;
    case 3: // Item 3
    pics = 150;
      break;
     case 4: // Item 4
     pics = 200;
      break;
     case 5: // Item 5
     pics = 250;
     break;
    default:
      terminal.println("Unknown item selected");
  }
}



void setup() {
  //Stepper
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(200);
  
  // Picture pin 
  pinMode(snap, OUTPUT);
  

  //Blynk Connect
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  stepper1.run();
  Blynk.run();
  
}
