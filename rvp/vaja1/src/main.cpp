#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void flash(int duration) {
  digitalWrite(LED_BUILTIN,HIGH);
  delay(duration);
  digitalWrite(LED_BUILTIN,LOW);
  delay(duration);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    flash(200);
  }
  delay(300);
  for (int i = 0; i < 3; i++) {
    flash(500);
  }
  delay(300);
  for (int i = 0; i < 3; i++) {
    flash(200);
  }
  delay(1000);
}
