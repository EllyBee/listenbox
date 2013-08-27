/**
  *  Function: xFade
  *  Ro : old red value
  *  Go : old green value
  *  Bo : old blue value
  *  Rn : new red value
  *  Gn : new green value
  *  Bn : new blue value
  *  time : The amount of time to do the fade (~100ths of a second)
  *  mode : The type of fade. LINEAR goes between the two colors in equal steps. EASED
  *         will go between the two colors using the sin function to provide a smoother
  *         transition.
  *
  *  Crossfade between two colors.
  */
void xFade(int Ro, int Go, int Bo, int Rn, int Gn, int Bn, long time, int mode) {
  if (mode == EASED) {
    easedFade(Ro, Go, Bo, Rn, Gn, Bn, time);
  } else {
    linearFade(Ro, Go, Bo, Rn, Gn, Bn, time);
  }

}
 
/**
  *  Function: linearFade
  *
  *  Implements the eased fade stepping. See xFade for argument definitions
  */           
void linearFade(int Ro, int Go, int Bo, int Rn, int Gn, int Bn, long time) {           
  int tempR, tempG, tempB;
  float stepR, stepG, stepB;
  
  stepR = (Rn - Ro) * 1.0 / (time);
  stepG = (Gn - Go) * 1.0 / (time);
  stepB = (Bn - Bo) * 1.0 / (time);
  for (long i=0; i<time; i++) {
    tempR = Ro + (stepR * i);
    tempG = Go + (stepG * i);
    tempB = Bo + (stepB * i);
    setColor(tempR, tempG, tempB);
    delay(10);
  }
  setColor(Rn, Gn, Bn); 
}

/**
  *  Function: easedFade
  *
  *  Implements the eased fade stepping. See xFade for argument definitions
  */
void easedFade(int Ro, int Go, int Bo, int Rn, int Gn, int Bn, long time) {           
  int tempR, tempG, tempB, rangeR, rangeG, rangeB;
  float radStep, tmpAng, tmpSin;
  
  radStep = RAD90 / time;
  rangeR = Rn - Ro;
  rangeG = Gn - Go;
  rangeB = Bn - Bo;
  
  for (long i=0; i<time; i++) {
    tmpSin = sin(radStep * i);
    tempR = Ro + rangeR * tmpSin;
    tempG = Go + rangeG * tmpSin;
    tempB = Bo + rangeB * tmpSin;
    setColor(tempR, tempG, tempB);
    delay(10);
  }
  setColor(Rn, Gn, Bn); 
}

/**
  *  Function: setColor
  *  R: the amound of red (0-255).
  *  G: the amount of green (0-255).
  *  B: the amount of blue (0-255).
  *
  *  Sets the color on the LED. The amount of each color is 0 (0%)to 255 (100%).
  */
void setColor(int R, int G, int B) {
  // We will XOR each color value with 255 since hardwarewise 255 represents off and 0
  // is 100% on. 
  analogWrite(LED_R, R^255); 
  analogWrite(LED_G, G^255);
  analogWrite(LED_B, B^255);
}
