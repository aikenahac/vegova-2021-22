// PWM - Pulse Width Modulation

#include <Arduino.h>

// int analog_value = 0;

// void setup() {
//   Serial.begin(9600);
//   DDRB |= (1 << 3); // Initialize PB3 as output
// }

// void pwm_function() {
//   analog_value = analogRead(A0);
//   Serial.println(analog_value);

//   PORTB |= (1 << 3); // Set PB3 as HIGH
//   delayMicroseconds(analog_value);

//   PORTB &=~ (1 << 3); // Set PB3 as LOW
//   delayMicroseconds(1023 - analog_value); // 10 bit A/D converter

//   // Vrednosti razdelkov se spreminjajo od 0 do 1023
//   // perioda 1024 ms
// }

// void loop() {
//   pwm_function();
// }

void setup() {
  Serial.begin(9600);
}

void loop() {
  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.print("Vrednost napetosti je ");
  Serial.print(voltage);
  Serial.println(" V");

  if (voltage > 3) {
    PORTB |= (1 << 3); // Set PB3 as HIGH
  } else if (voltage < 2) {
    PORTB |= (1 << 4); // Set PB4 as HIGH
  } else {
    PORTB &=~ (1 << 3); // Set PB3 as LOW
    PORTB &=~ (1 << 4); // Set PB4 as LOW
  }
  
  delay(1);
}