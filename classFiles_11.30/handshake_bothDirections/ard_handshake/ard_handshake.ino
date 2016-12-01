int ledPin = 13;
boolean ledState = LOW; // for toggling LED on-off

int sensorPin = A1;

char val; // Data received from the serial port


void setup() 
{
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
  establishContact();  // send a byte to establish contact 
}

void loop()
{
  if (Serial.available() > 0) { // If data is available to read,
    val = Serial.read(); // read it and store it in val

    if(val == '1') //if we get a 1
    {
       ledState = !ledState; //flip the ledState
       digitalWrite(ledPin, ledState); 
    }
    delay(40);
  } 
  else { //if we've read the data already
    Serial.write(analogRead(sensorPin));
    delay(20);
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
  Serial.println("A");   // send a capital A
  delay(300);
  }
}
