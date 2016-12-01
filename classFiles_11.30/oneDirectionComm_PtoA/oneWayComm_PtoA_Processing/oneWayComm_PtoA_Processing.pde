import processing.serial.*;

Serial myPort;

void setup(){
  
  myPort = new Serial(this, Serial.list()[5], 9600);
  
}

void draw(){
  
  if(mousePressed){
    
    myPort.write('1');
    
    //you can also send non binary values
    //  myPort.write(mouseY);
  }
  
  else {
    myPort.write('0');
  }
   
}
