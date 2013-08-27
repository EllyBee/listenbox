void checkInput(){
  
   if (Serial.available()) {
    /* read the most recent byte */
    val = Serial.read();
    /*ECHO the value that was read, back to the serial port. */
    Serial.write(val);
    turnMotor();
  }
  
  if (val == 'H') { // If H was received  - ascii 72
    
    ledON();
    happyLoop();
    
  } 
  if (val == 'I') { // ascii 73
    
    ledPulse();  //used to show messages available.
    sadLoop();
  } 
  
  else{
    
  }
  
   delay(100); // Wait 100 milliseconds for next reading
}
