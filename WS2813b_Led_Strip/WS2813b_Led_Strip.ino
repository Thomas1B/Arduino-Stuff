#include <FastLED.h>

// Definining pins
#define DATA_PIN 3  // data pin
#define POT_PIN A3


const int NUM_LEDS = 300;  // number of leds

// Define the array of leds
CRGB leds[NUM_LEDS];

// ********** Functions ******************

int read_pot() {
  float pot = analogRead(POT_PIN);

  float scale = map(pot, 20, 915, 0, 255);
  // if (Serial) { Serial.println(scale); }
  return scale;
}


// ********** Main Program ******************


void setup() {
  Serial.begin(9600);
  pinMode(POT_PIN, INPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void colorGroup(int start, int num_leds, long int color = CRGB::Black) {
  /*
  Function to color a consecutive group of leds.
  */
  for (int i = start; i < (start + num_leds); i++) {
    leds[i] = color;
  }
}

void dke(int start, int num_led) {
  colorGroup(0 + start, num_led, CRGB::Red);
  colorGroup(num_led + start, num_led, CRGB::Gold);
  colorGroup((2*num_led) + start, num_led, CRGB::Blue);
}

void loop() {
  FastLED.setBrightness(constrain(read_pot(), 0, 255));

  // Turn the LED on, then pause
  dke(0, 3);
  dke(10, 3);
  // dke(19, 3);

  FastLED.show();
}
