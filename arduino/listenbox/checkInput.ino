//void checkInput(){
void serialEvent(){

  //if (Serial.available()) {
  /* read the most recent byte */
  val = Serial.read();
  /*ECHO the value that was read, back to the serial port. */
  //Serial.write(val);
  if(val > 0){
    motorOn = true;
  }
  //turnMotor();
  //reset();
  //}

  if (val == 'H') { // If H was received  - ascii 72

    sad = false;
    happy = true;

  } 
  if (val == 'I') { // ascii 73

    happy = false;
    sad = true;
  } 

  else{

  }

  delay(100); // Wait 100 milliseconds for next reading
}

