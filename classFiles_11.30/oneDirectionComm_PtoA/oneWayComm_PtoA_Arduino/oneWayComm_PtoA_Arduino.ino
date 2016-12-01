int ledPin = 13;

int val = 0;

void setup(){
  
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop(){
  
  if(Serial.available()){
    val = Serial.read();
  }
  
  //example of using analog output
  //analogWrite(somePWMPin, val);
  
  if(val == '1'){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(20);
}
