#include <Arduino.h>

int sensor_value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensor_value = analogRead(A0);
  float max_voltage = 5.0;

  float voltage = sensor_value * (5.0 / 1023.0);
  Serial.print("Vrednost napetosti je ");
  Serial.print(voltage);
  Serial.println(" V"); 

  if (voltage < max_voltage/3) {
    Serial.println(100);
  } else if (voltage > ((max_voltage/3) * 2)) {
    Serial.println(900);
  } else {
    Serial.println(200);
  }
}
