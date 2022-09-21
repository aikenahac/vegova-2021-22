#include <Arduino.h>

void setup() {
  pinMode(3, INPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // Če je gumb pritisnjen se LED prižge
  // if (digitalRead(3) == HIGH) {
    // digitalWrite(11, HIGH);
  // } else {
    // digitalWrite(11, LOW);
  // }

  // Če se gumb drži, lučka utripa
  if (digitalRead(3) == HIGH) {
    digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);
    delay(100);
  }
}