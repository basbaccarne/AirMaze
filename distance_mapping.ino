// This script takes the value from a distance sensor and maps the measured distance to a PWM signal

// Pins
const int trigPin = 2; // Trigger pin
const int echoPin = 3; // Echo pin
const int motorPin = 9; // Motor Vcc

// Variables
float distance_cm =0; // measured distance (in cm)
float PWM_value = 0; // PWM signal (0 to 255)
const float max_distance = 90; // adapt this to the maximum value measured by the distance sensor

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

// Distance sensor function
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
  distance_cm = duration * 0.0343 / 2.0;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.print(" cm");
}

void loop() {
  // Run the function to detect the distance
  distance();
  // Map the distance value to the PWM signal (closer = faster)
  PWM_value = map(distance_cm, 0, max_distance, 255, 0);
  Serial.print(" // PWM:  ");
  Serial.println(PWM_value);
  // Write the PWM signal
  analogWrite(motorPin, PWM_value);
  // delay
  delay(100);
}
