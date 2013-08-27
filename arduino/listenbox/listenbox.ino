#include <Servo.h> 

//motor stuff//////////////////
Servo myservo;

//serial stuff
byte val;

//led stuff///////////////////////
const int ledPin =  4;      // the number of the LED pin

//led pulse stuff
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds)

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
  //setup motor
  myservo.attach(9);
  
  //set up led
  pinMode(ledPin, OUTPUT);
  
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

  //check servo working///////////////
  myservo.write(0);            
  delay(50);                      
  myservo.write(90); 
  delay(50);
  myservo.write(0);
  delay(50);

  //check led working//////////////////////
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);

} 


void loop() 
{ 
  checkInput();
  
  happyLoop();
 
} 


