#include <Arduino.h>

int lightPin = 0;
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

int leds = 0;

void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void updateShiftRegister() {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
}

void loop() {
    int reading = analogRead(lightPin);

    int numLEDSlit = reading / 128;

    if (numLEDSlit > 8) {
        numLEDSlit = 8;
    }

    leds = 0;

    for (int i = 0; i < numLEDSlit; i++) {
        leds = leds + (1 << i);
    }

    updateShiftRegister();
}