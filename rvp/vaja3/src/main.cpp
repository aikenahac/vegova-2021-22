#include <Arduino.h>

const int button1 = 7;
const int button2 = 6;
const int button3 = 5;
const int button4 = 4;
const int button5 = 3;

const int led1 =  12;
const int led2 = 11;
const int led3 = 10;
const int led4 = 9;
const int led5 = 8;

const int buzzer = 2;

int b1state = 0;
int b2state = 0;
int b3state = 0;
int b4state = 0;
int b5state = 0;

void turnOn(int button, int led) {
  if (button == HIGH) {
    tone(buzzer, 1000, 1000);
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
}

void loop() {
  b1state = digitalRead(button1);
  b2state = digitalRead(button2);
  b3state = digitalRead(button3);
  b4state = digitalRead(button4);
  b5state = digitalRead(button5);

  turnOn(b1state, led1);
  turnOn(b2state, led2);
  turnOn(b3state, led3);
  turnOn(b4state, led4);
  turnOn(b5state, led5);
}