void happyLoop(){
  
 xFade(60, 10, 0, 255, 255, 0, 200, EASED);
 xFade(255, 255, 0, 60, 10, 0, 200, EASED);
  
}


void sadLoop(){
  
  xFade(0, 0, 255, 255, 0, 255, 200, EASED);
  xFade(255, 0, 255, 0, 0, 255, 200, EASED);
  
}



void reset(){

  setColor(0,0,0);
  
}
