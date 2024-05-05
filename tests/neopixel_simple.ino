// Simple NeoPixel chase test

#include <Adafruit_NeoPixel.h>

// Connect Din (Neopixel) to Digital 6 (Arduino)
// Connect 5VDC (Neopixel) to 5V (Arduino)
const int ledPin = 6;
const int N_LEDs = 8;

// configure neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDs, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  // initiate neopixel strip
  strip.begin();
}

void loop() {
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}