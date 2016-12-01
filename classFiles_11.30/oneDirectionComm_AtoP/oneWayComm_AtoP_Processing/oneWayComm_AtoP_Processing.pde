import processing.serial.*;

Serial myPort;

int var = 0;

void setup(){
  
  size(500,500);
  
  printArray( Serial.list() );
  
  //myPort = new Serial(this, "/dev/tty.usbmodem1411", 9600);
  myPort = new Serial(this, Serial.list()[5], 9600);
}

void draw(){
  
  background(0);
  
  if(myPort.available() > 0){
    var = myPort.read();
    println(var);
  }
  
  ellipse(width/2, height/2, var, var);
}
