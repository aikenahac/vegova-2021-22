#include <Arduino.h>

const int button1 = 5;
const int button2 = 6;
const int button3 = 7;

const int buzzer = 8;

const int toneC5 = 956;
const int toneD5 = 852;
const int toneE5 = 759;

int state = 0;

void toneOwn(int note, int duration) {

}

void kuzaPazi() {
  for (int i = 0; i < 4; i++) {
    tone(buzzer, toneE5, 100);
    delay(400);
  }
  for (int i = 0; i < 4; i++) {
    tone(buzzer, toneD5, 100);
    delay(400);
  }
  for (int i = 0; i < 2; i++) {
    tone(buzzer, toneC5, 100);
    delay(400);
  }
  for (int i = 0; i < 2; i++) {
    tone(buzzer, toneD5, 100);
    delay(400);
  }
  for (int i = 0; i < 2; i++) {
    tone(buzzer, toneE5, 100);
    delay(400);
  }
  tone(buzzer, toneE5, 300);
  delay(5000);
}

void playSound(int button, int note) {
  state = digitalRead(button);

  if (state == HIGH) {
    tone(buzzer, note, 100);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}

void loop() {
  // kuzaPazi();
  playSound(button1, toneC5);
  playSound(button2, toneD5);
  playSound(button3, toneE5);
}