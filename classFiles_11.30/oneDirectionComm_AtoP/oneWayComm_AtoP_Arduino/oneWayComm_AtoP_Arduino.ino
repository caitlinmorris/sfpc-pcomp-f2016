int sensorPin = A1;

void setup(){
  
  Serial.begin(9600);
  
}

void loop(){
  
  int mySensorValue = analogRead(sensorPin);
  
  int mappedSensorValue = map(mySensorValue, 0, 1023, 0, 255);
  
  Serial.write(mappedSensorValue);
  
  delay(20);
  
}
