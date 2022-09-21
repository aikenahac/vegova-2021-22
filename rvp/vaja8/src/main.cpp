// 7-segment display

#include <Arduino.h>

void init() {
  DDRB |= 0x0F;
  DDRD |= 0xF0;
}

int dekodirnik(int stevka) {
  switch (stevka) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      return 0x00F0;
      break;
  }
  
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  PORTB &= 0xF0;
  PORTD &= 0x0F;
}