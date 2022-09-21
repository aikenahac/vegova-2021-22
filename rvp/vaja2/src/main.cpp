#include <Arduino.h>

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = HIGH;
  // print out the state of the button:
  if (digitalRead(pushButton) != buttonState) {
    Serial.println("Button has been pressed!");
    buttonState = digitalRead(pushButton);
  }
  delay(1);        // delay in between reads for stability
}