import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress serverLocation;

void setup() {
  size(400,400);
  // start oscP5, listening for incoming messages at port 12345
  oscP5 = new OscP5(this,12345);
  
  serverLocation = new NetAddress("127.0.0.1",12000);
}


void draw() {
  background(0);  
}

void mousePressed() {

  OscMessage myMessage = new OscMessage("/test");
  
  myMessage.add(mouseX);
  myMessage.add(mouseY);
  
  oscP5.send(myMessage, serverLocation); 
  
}


void oscEvent(OscMessage incomingMessage) {
  
  print("incoming message | ");
  print(" addrpattern: "+incomingMessage.addrPattern());
  println(" typetag: "+incomingMessage.typetag());

  
  if(incomingMessage.checkAddrPattern("/mouse")==true) {
    //check if the typetag is the right one
    if(incomingMessage.checkTypetag("ii")) {

      int xVal = incomingMessage.get(0).intValue();  
      int yVal = incomingMessage.get(1).intValue();

      println(" values: "+xVal+", "+yVal);
    }  
  }  
}


