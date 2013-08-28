#include <Servo.h> 

//motor stuff//////////////////
Servo myservo;
//servo timer stuff
boolean motorOn = false;
int motorCount = 0;
long motorinterval = 5;           // interval at which to pause servo motor
long previousMillis_motor = 0; 
//change this number to control how many times the box sits up and down
int nudges = 4;

//serial stuff
byte val;

//booleans///////////////////////
boolean happy = false;
boolean sad = false;


//RGB Led stuff/////////////////////
const int LED_R = 3;
const int LED_G = 5;
const int LED_B = 6;

// Internal use constants.
const int LINEAR = 1;
const int EASED = 2;
const float RAD90 = 1.5708;

// Internal globals.
int Rold, Gold, Bold;
int Rnew, Gnew, Bnew;
int duration;

////////////////////////////////

void setup() 
{ 
  //set up led
  //pinMode(ledPin, OUTPUT);
  
  //set up rgb led//////////////////////////
 // Set the pins for OUTPUT
  pinMode(LED_R, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_G, OUTPUT);

  // Boot sequence to verify wiring.
  // Fade in and out red
  xFade(0, 0, 0, 255, 0, 0, 100, EASED);
  xFade(255, 0, 0, 0, 0, 0, 100, EASED);
  
  // Fade in and out green
  xFade(0, 0, 0, 0, 255, 0, 100, EASED);
  xFade(0, 255, 0, 0, 0, 0, 100, EASED);
  
  // Fade in and out blue
  xFade(0, 0, 0, 0, 0, 255, 100, EASED);
  xFade(0, 0, 255, 0, 0, 0, 100, EASED);
  
  //start serial communication/////////
  Serial.begin(9600);
  
   //setup motor
  myservo.attach(10);
  //check servo working///////////////
  myservo.write(0);            
  delay(15);                      
  myservo.write(90); 
  delay(15);
  myservo.write(0);
  delay(15);
  myservo.write(90); 
  delay(15);
  
  turnMotor();
  happy = true; 

} 


void loop() 
{ 
  //checkInput();
  if(motorOn) turnMotor();
  if(happy) happyLoop();
  if(sad) sadLoop();
 
} 


