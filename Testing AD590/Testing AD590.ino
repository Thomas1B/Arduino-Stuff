#define sensor A0;


void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(750);

  float val = analogRead(A0);
  float volt = val * (5.0/1023.0);
  float current = (volt/10e3)/1e-6; // in mA.
  float temperature = current - 273.15; // converting to C.

  Serial.print("Raw: ");
  Serial.print(val);

  Serial.print(", V: ");
  Serial.print(volt);

  Serial.print(", Currrent: ");
  Serial.print(current);
  Serial.print(" mA");

  Serial.print(", Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
}
