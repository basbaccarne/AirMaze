// Neopixel test with a dummy variable to simulate increases and decreases from an input variable

// Libraries
#include <Adafruit_NeoPixel.h>

// Pins
const int ledPin = 6;
const int N_LEDs = 8;

// Varibles for Neopixel control
unsigned long previousMillis_LED = 0;
const int N_LEDs = 8;
int ledID = 0;

// Variables for Dummy
unsigned long previousMillis_SpeedDummy = 0;
int dummy_value = 25;

// Configure neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDs, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  Serial.begin(9600);
}

void loop() {
  // General clock
  unsigned long currentMillis = millis();

  // Dummy: getting closer and then back again (dummy_value)
  if (currentMillis - previousMillis_SpeedDummy > 50) {  // run each 50 millisecons

    dummy_value++;
    if (dummy_value > 150) {
      dummy_value = 25;
    }
    // Serial.print("Speed: ");
    // Serial.println(dummy_value);

    previousMillis_SpeedDummy = currentMillis;
  }

  // LED: moves faster and slower acording to the Dummy (dummy_value)
  if (currentMillis - previousMillis_LED > dummy_value) {  // run at a speed dependent of the dummy variable

    ledID++;  // move one LED up
    if (ledID > N_LEDs + 1) {
      ledID = 0;
    }

    strip.setPixelColor(ledID, strip.Color(0, 0, 255));  // set current LED ID to blue
    strip.setPixelColor(ledID - 2, 0);                   // erase pixel 2 steps back
    strip.show();                                        // light it up!

    previousMillis_LED = currentMillis;
  }

  
}