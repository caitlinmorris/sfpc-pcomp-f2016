char val; // Store data received from the serial port

int ledPin = 13; // set up LED pin

int firstSensorPin = A1; // set up sensor pins
int secondSensorPin = A0;
int thirdSensorPin = A2;

int firstSensorVal = 0; // variables to store sensor data
int secondSensorVal = 0;
int thirdSensorVal = 0;

boolean ledState = LOW; //to toggle our LED

void setup() 
{
  pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
  Serial.begin(9600); // set baud rate to 9600 bps
  establishContact();  // function sends a byte out until receiver responds 
}

void loop()
{
  if (Serial.available() > 0) { // If data is available to read,
    val = Serial.read(); // read it and store it in val

    if(val == '1') //if we get a 1 from Processing
    {
      ledState = !ledState; //flip the ledState
      digitalWrite(ledPin, ledState); 
    }
    delay(40);

  }

    else {
      firstSensorVal = analogRead(firstSensorPin);
//      secondSensorVal = 0;
//      thirdSensorVal = 10;
      secondSensorVal = analogRead(secondSensorPin);
      thirdSensorVal = analogRead(thirdSensorPin);
      
      Serial.write(firstSensorVal); // write the sensor values to the port
      Serial.write(secondSensorVal);
      Serial.write(thirdSensorVal);
      delay(10);
    }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("A");   // send a capital A
    delay(300);
  }
}



