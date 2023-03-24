/*
Program to test to a NTC temperature probe/sensor.

*/


// Pins for temperature probes
#define sensor1 A3
int temp_pins[] = {sensor1}; // array of pins

// Value of resistor in parallel with probe.
const float temperature_resistor = 1e4;

const int len = 1; // number of prboes


int count = 1;
void read_thermistor_resistance() {
  // Function to read in temperature from eachs sensor
  float resistance[len] = {};

  for (int i = 0; i < len; i++) {
    float val = analogRead(temp_pins[i]);
    val = (1023/val) - 1; // (1023/ADC - 1)
    resistance[i] = temperature_resistor/val;
    Serial.print("Count ");
    Serial.print(count);
    Serial.print(": ");
    Serial.println(resistance[i]);
    count++;
  }

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor1, INPUT);

}

const float interval = 1000;

double last = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - last >= interval) {
    last = millis();
    read_thermistor_resistance();
  }
}
