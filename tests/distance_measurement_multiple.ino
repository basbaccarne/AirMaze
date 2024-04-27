// simple code to detect the distance and print the reseult in cm to the serial monitor
// for six ultrasonic sensors (D2-D13) (keep D0 and D1 free for serial communication)
// even pins are triggers, uneven pins are echos

// Define pins for the ultrasonic sensor
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int trigPin3 = 6;
const int echoPin3 = 7;
const int trigPin4 = 8;
const int echoPin4 = 9;
const int trigPin5 = 10;
const int echoPin5 = 11;
const int trigPin6 = 12;
const int echoPin6 = 13;

float distance_cm = 0;
float dist1 = 0;
float dist2 = 0;
float dist3 = 0;
float dist4 = 0;
float dist5 = 0;
float dist6 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Initiazing ...");
  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin6, INPUT);
}

void loop() {
  distance(trigPin1, echoPin1);
  dist1 = distance_cm;
  Serial.print("sensor 1: ");
  Serial.print(dist1);

  distance(trigPin2, echoPin2);
  dist2 = distance_cm;
  Serial.print(" || sensor 2: ");
  Serial.print(dist2);

  distance(trigPin3, echoPin3);
  dist3 = distance_cm;
  Serial.print(" || sensor 3: ");
  Serial.print(dist3);

  distance(trigPin4, echoPin4);
  dist4 = distance_cm;
  Serial.print(" || sensor 4: ");
  Serial.print(dist4);

  distance(trigPin5, echoPin5);
  dist5 = distance_cm;
  Serial.print(" || sensor 5: ");
  Serial.print(dist5);

  distance(trigPin6, echoPin6);
  dist6 = distance_cm;
  Serial.print(" || sensor 6: ");
  Serial.println(dist6);

  delay(100);

}

void distance(int trigPin, int echoPin){
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
}