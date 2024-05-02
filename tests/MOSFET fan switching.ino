// simple code to open and close the MOSFET (signal on digital 3)

const int signalPin = 3;

void setup() {
  pinMode(signalPin, OUTPUT); // Define pin as output
}

void loop() {
  digitalWrite(signalPin, HIGH); // Set the pin to HIGH (turns on the motor)
  delay(5000); // Wait for 5 seconds
  digitalWrite(signalPin, LOW); // Set the pin to LOW (turns off the motor)
  delay(5000); // Wait for 5 seconds
}
