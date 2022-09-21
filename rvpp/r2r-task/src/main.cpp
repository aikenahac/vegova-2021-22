#include <Arduino.h>

void setup() { 
    Serial.begin(9600);
    DDRD = B11111111; // Port D (pin 0-7) uporabljen kot izhod
}

void loop() {
    for ( int i = 0; i < 256; i++) {
        PORTD = i;
        delay(10);
        Serial.println(analogRead(A0));
    }
}