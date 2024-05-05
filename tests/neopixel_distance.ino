// Load libraries
#include <Adafruit_NeoPixel.h>

// Define pins
const int trigPin = 2;   // HC-SR04 trigger pin
const int echoPin = 3;   // HC-SR04 echo pin
const int motorPin = 8;  // LN298N IN1
const int SpeedPin = 9;  // LN298N ENa
const int ledPin = 6;    // Neopixel DIN

// Define variables for HC-SR04 distance measurement
unsigned long previousMillis_distance = 0;  // timer
float distance_cm = 0;                      // measured distance (in cm)
float PWM_value = 0;                        // PWM signal (0 to 255)
const float min_distance = 90;              // adapt this to the distance at which the motor should start

// Define varibles for Neopixel control
unsigned long previousMillis_LED = 0;  // timer
const int N_LEDs = 8;                  // 8 LEDs on the strip
int ledID = 0;                         // LED ID counter for chase effect

// Configure neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDs, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(SpeedPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  strip.begin();
}

// Function: Measure the distance in CM using the HC-SR04 (echolocation)
void distance() {
  // Fire a pulse!
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
  Serial.println(" cm");
}

void loop() {
  // General clock
  unsigned long currentMillis = millis();

  // Run the function to detect the distance // responsiveness: each 100 millisecons
  if (currentMillis - previousMillis_distance > 100) {
    distance();
    previousMillis_distance = currentMillis;
  }

  // Map the distance value to the PWM signal (closer = faster motor)
  // But only if an object is within the range of min_distance
  if (distance_cm < min_distance) {
    PWM_value = map(distance_cm, 0, min_distance, 255, 0);  // play with these mappings in the actual environment
    digitalWrite(motorPin, HIGH);                           // turn motor on
    analogWrite(SpeedPin, PWM_value);                       // set motor speed
    Serial.print(" // PWM:  ");
    Serial.println(PWM_value);
  } else {
    digitalWrite(motorPin, LOW);  // turn the motor off
  }

  // Drive the LED on the Neopixel stick:
  // Moves faster and slower acording to the distance (closer = faster)
  if (currentMillis - previousMillis_LED > 255 - PWM_value) {  // speed = dependent of PWM value
    ledID++;
    if (ledID > N_LEDs + 1) {
      ledID = 0;
    }
    strip.setPixelColor(ledID, strip.Color(0, 0, 255));  // set current LED ID to blue
    strip.setPixelColor(ledID - 2, 0);                   // erase pixel 2 steps back
    strip.show();                                        // light it up!

    previousMillis_LED = currentMillis;
  }
}