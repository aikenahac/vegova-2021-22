// 7-segment display

#include <Arduino.h>

void setup() {
  DDRB |= 0x0f;
  DDRD |= 0xfc;
}

int decoder(int number) {
  switch (number) {
    case 0: return 0x03F0;
    case 1: return 0x0060;
    case 2: return 0x05B0;
    case 3: return 0x04F0;
    case 4: return 0x0660;
    case 5: return 0x06D0;
    case 6: return 0x07D0;
    case 7: return 0x0070;
    case 8: return 0x07F0;
    case 9: return 0x06F0;
  }
}

void loop() {
  int decodedValue = 0;
  int ones = 0, tens = 0, hundreds = 0, thousands = 0;

  for (int i = 0; i < 100; i++) {
    ones = i%10;
    tens = i/10;
  
    for (int j = 0; j < 20; j++) {
      // Ones

      PORTB = 0xF0;
      PORTD = 0x03;

      decodedValue = decoder(ones);

      PORTB |= decodedValue >> 0;
      PORTD |= decodedValue;

      digitalWrite(2, 0);
      digitalWrite(3, 1);
      delay(1000);

      // Tens
      PORTB = 0xF0;
      PORTD = 0x03;
  
      decodedValue = decoder(tens);
  
      // Cleanup
      PORTB |= decodedValue >> 0;
      PORTD |= decodedValue;
  
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      delay(1000);
    }
  }

}
