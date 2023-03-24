#include <FastLED.h>

// Definining pins
#define DATA_PIN 2  // data pin
#define POT_PIN A3


const int NUM_LEDS = 10; // number of leds

// Define the array of leds
CRGB leds[NUM_LEDS];

// ********** Functions ******************

int read_pot() {
  float pot = analogRead(POT_PIN);

  float scale = map(pot, 0, 915, 0, 255);
  Serial.println(scale);
  return scale;
}


// ********** Main Program ******************


void setup() {
  Serial.begin(9600);
  pinMode(POT_PIN, INPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}


void loop() {
  // Turn the LED on, then pause
  for (int i = 0; i < 5; i++) {
    leds[i] = CRGB::Red;
  }
  for (int i = 3; i < 7; i++) {
    leds[i] = CRGB::Gold;
  }
  for (int i = 7; i < 10; i++) {
    leds[i] = CRGB::Blue;
  }
  FastLED.setBrightness(constrain(read_pot(), 0, 255));
  FastLED.show();
}
