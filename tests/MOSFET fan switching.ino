// simple code to detect the distance and print the reseult in cm to the serial monitor
// ultrasonic sensor (HC-SR04) trigger on Digital 2, echo on Digital 3

const int pin = 3;

void setup() {
  pinMode(pin, OUTPUT); // Define pin as output
}

void loop() {
  digitalWrite(pin, HIGH); // Set the pin to HIGH (turns on the motor)
  delay(5000); // Wait for 5 seconds
  digitalWrite(pin, LOW); // Set the pin to LOW (turns off the motor)
  delay(5000); // Wait for 5 seconds
}