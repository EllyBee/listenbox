/*void turnMotor(){

  if(motorCount < nudges){

    if (myservo.read() > 0)
      myservo.write(0);     
    else
      myservo.write(90);     
    delay(50);
    motorCount++;
  }
  else{
    
   motorCount = 0; 
    
  }

}*/


/*void turnMotor(){

  if(motorCount < 6){

     unsigned long currentMillis = millis(); 
    if(currentMillis - previousMillis_motor > motorinterval) {
      // save the last time you blinked the LED 
      previousMillis_motor = currentMillis;   
      if (myservo.read() > 0)
        myservo.write(0);     
      else
        myservo.write(90);

      motorCount++;

    }
  }
  else{
    
   motorOn = false;
   motorCount = 0;
    
  }

}*/

void turnMotor(){

  for (int i=0; i < 4; i++){
    
      if (myservo.read() > 0)
        myservo.write(0);     
      else
        myservo.write(90);
        
       delay(400);

      //motorCount++;

    }

    
   motorOn = false;
   //motorCount = 0;
   

}

