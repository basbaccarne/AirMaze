// simple code to detect the distance and print the reseult in cm to the serial monitor
// ultrasonic sensor (HC-SR04) trigger on Digital 2, echo on Digital 3

// Define pins for the ultrasonic sensor
const int trigPin = 2; // Trigger pin
const int echoPin = 3; // Echo pin

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void distance(){
// Send a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the echo to return
  long duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters (speed of sound = 343 m/s)
  float distance_cm = duration * 0.0343 / 2.0;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
}

void loop() {
  distance();
  // Set latency
  delay(100);
}