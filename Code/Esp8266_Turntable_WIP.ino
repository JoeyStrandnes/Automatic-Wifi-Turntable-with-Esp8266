#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
#define BLYNK_EXPERIMENTAL
#include <CustomStepper.h>


CustomStepper stepper(2, 3, 4, 5, (byte[]){8, B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001}, 4075.7728395, 12, CW); //Setting up stepper

char * ssid = "SSID"; //Network name
char * pass = "pswd"; //Password
char * auth = "Auth"; 

int pics = 50;
double steps; 
double pos;
int counter;

int snap = D6;


WidgetTerminal terminal(V1);

//Terminal
BLYNK_WRITE(V1);


//Delay

void Blynk_Delay(int milli){
   int end_time = millis() + milli;
   while(millis() < end_time){
       Blynk.run();
       yield();
   }
}

//Buttons

BLYNK_WRITE(V2){
  int StartTurntable = param.asInt();

  terminal.print("You have choosen to take ");
  terminal.print(pics);
  terminal.println("pictures");
  
  Blynk_Delay(5000);
  
  if (StartTurntable == 1){
    
  
  steps = 360/pics;
  
  while (counter < pics){

  pos = counter * steps;
  
  stepper.setDirection(CCW);
  stepper.rotateDegrees(steps);
  terminal.print("Current possition: ");
  terminal.print(pos);
  terminal.println(" degrees");
  
  Blynk_Delay(500);
  digitalWrite(snap, HIGH);
  Blynk_Delay(500);
  digitalWrite(snap, LOW);
  Blynk_Delay(3000);
  
  counter++;
    
    
    }
  }

  else{
    terminal.println("Stopped");
  }
}

BLYNK_WRITE(V3){
  int StopTurntable = param.asInt();
  if (StopTurntable == 1){
    terminal.println("Stopped");
  }

  else{
    
  }
}


//Menu
BLYNK_WRITE(V0) {
  switch (param.asInt())
  {
    case 1: // Item 1
    pics = 50;
      terminal.println("You have selected 50");
      break;
    case 2: // Item 2
    pics = 100;
      terminal.println("You have selected 100");
      break;
    case 3: // Item 3
    pics = 150;
      terminal.println("You have selected 150");
      break;
     case 4: // Item 4
     pics = 200;
      terminal.println("You have selected 200");
      break;
     case 5: // Item 5
     pics = 250;
      terminal.println("You have selected 250");
     break;
    default:
      Serial.println("Unknown item selected");
  }
}



void setup() {
 Serial.begin(115200);
 
  pinMode(snap, OUTPUT);
  digitalWrite(snap, LOW);
 
 stepper.setRPM(12);
 stepper.setSPR(4075.7728395);



 
 Serial.print("Ready to start");
  
 Blynk.begin(auth, ssid, pass);
}

void loop() {
  
Blynk.run();
/*
if (StartTurntable == 1){
  steps = 360/pics;

  if (StopTurntable == 0){
  pos = counter * steps;
  
  stepper.setDirection(CW);
  stepper.rotateDegrees(steps);
  terminal.print("Current possition: ");
  terminal.println(pos);
  terminal.println(" degrees");

  counter++;
  
  delay(1000);
    
    }
  
  }
*/

}









