/*
Most of the code was found here: https://www.youtube.com/watch?v=cYCTMdUi8P0&t=447s

Then I added the BfButton library to make the button part easier.
*/

#include <BfButton.h>  // For Encoder.

// Pins
#define CLK 2
#define DT 3
#define SW 4

// defining button.
BfButton btn(BfButton::STANDALONE_DIGITAL, SW, true, LOW);

const float increment = 1;
const float holdTime = 1000;

// variables for debouncing
long TimeOfLastDebounce = 0;
const long DelayofDebounce = 0.01;

// Store previous states
int preCLK;
int preDATA;


// Rotary Value
float value = 0;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(DT, INPUT);
  pinMode(CLK, INPUT);
  pinMode(SW, INPUT_PULLUP);

  preCLK = digitalRead(CLK);
  preDATA = digitalRead(DT);
  Serial.println(value);

  btn.onPress(read_button)               // single click
    .onDoublePress(read_button)          // double click
    .onPressFor(read_button, holdTime);  // hold for 1sec for turning on/off
}

void loop() {
  // put your main code here, to run repeatedly:
  btn.read();
  if ((millis() - TimeOfLastDebounce) > DelayofDebounce) {
    check_rotary();
    preCLK = digitalRead(CLK);
    preDATA = digitalRead(DT);
    TimeOfLastDebounce = millis();
  }
}

void read_button(BfButton *btn, BfButton::press_pattern_t pattern) {
  // Function to read button on the Encoder.

  switch (pattern) {

    case BfButton::SINGLE_PRESS:
      Serial.println("Single Press");
      break;

    case BfButton::DOUBLE_PRESS:
      Serial.println("Double Press");
      break;

    case BfButton::LONG_PRESS:
      Serial.println("Button Held");
      break;
  }
}

void check_rotary() {
  if ((preCLK == 0) && (preDATA == 1)) {
    if ((digitalRead(CLK) == 1) && (digitalRead(DT) == 0)) {
      value += increment;
      Serial.println(value);        
    }
    if ((digitalRead(CLK) == 1) && (digitalRead(DT) == 1)) {
      value -= increment;
      Serial.println(value);        
    }
  }

  if ((preCLK == 1) && (preDATA == 0)) {
    if ((digitalRead(CLK) == 0) && (digitalRead(DT) == 1)) {
      value += increment;
      Serial.println(value);        
    }
    if ((digitalRead(CLK) == 0) && (digitalRead(DT) == 0)) {
      value -= increment;
      Serial.println(value);        
    }
  }

  if ((preCLK == 1) && (preDATA == 1)) {
    if ((digitalRead(CLK) == 0) && (digitalRead(DT) == 1)) {
      value += increment;
      Serial.println(value);        
    }
    if ((digitalRead(CLK) == 0) && (digitalRead(DT) == 0)) {
      value -= increment;
      Serial.println(value);        
    }
  }

  if ((preCLK == 0) && (preDATA == 0)) {
    if ((digitalRead(CLK) == 1) && (digitalRead(DT) == 1)) {
      value += increment;
      Serial.println(value);  
    }
    if ((digitalRead(CLK) == 1) && (digitalRead(DT) == 1)) {
      value -= increment;
      Serial.println(value);  
    }
  }
}
