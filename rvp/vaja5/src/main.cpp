#include <Arduino.h>

int sensorValue = 0;

float temperature = 0.0;

float x11 = 300.0;
float x22 = 900.0;

float y11 = 20.0; 
float y22 = 80.0;

float directionalCoefficient = 0.0;
float intersection = 0.0;

void setup() {
  Serial.begin(9600);

  directionalCoefficient = (y22 - y11) / (x22 - x11);
  intersection = y11 - (directionalCoefficient * x11);
}

void loop() {
  sensorValue = analogRead(A0);

  temperature = directionalCoefficient * sensorValue + intersection;

  Serial.println(temperature);

  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  delay(200);
}