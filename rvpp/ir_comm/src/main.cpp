#include <Arduino.h>
#include <IRremote.h>

// int RECV_PIN = 7;

// IRrecv irrecv(RECV_PIN);

// decode_results results;

// void setup() {
//     Serial.begin(9600);

//     irrecv.enableIRIn(); // Start IR sprejemnika
// }

// void loop() {
//     if (irrecv.decode(&results)) {
//         Serial.println(results.value, DEC);
//         irrecv.resume(); // Pripravljen na sprejem naslednje IR kode
//     }

//     delay(100);
// }

int ir_pin = 7;

int red_led = 10;
int yellow_led = 9;
int green_led = 8;

int red_state = 0;
int yellow_state = 0;
int green_state = 0;

IRrecv irrecv(ir_pin);

decode_results results;

void setup() {
  Serial.begin(9600);
  
  irrecv.enableIRIn();

  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    long int decCode = results.value;

    Serial.println(results.value);

    switch (results.value) {
      case 16724175: // Turn on red LED
        if (red_state == 0) {
          red_state = 1;
          digitalWrite(red_led, HIGH);
        } else if (red_state == 1) {
          red_state = 0;
          digitalWrite(red_led, LOW);
        }
        break;
      case 16718055: // Turn on yellow LED
        if (yellow_state == 0) {
          yellow_state = 1;
          digitalWrite(yellow_led, HIGH);
        } else if (yellow_state == 1){
          yellow_state = 0;
          digitalWrite(yellow_led, LOW);
        }
        break;
      case 16743045: // Turn on green LED
        if (green_state == 0) {
          green_state = 1;
          digitalWrite(green_led, HIGH);
        } else if (green_state == 1) {
          green_state = 0;
          digitalWrite(green_led, LOW);
        }
        break;
    }
    irrecv.resume();
  }
  delay(10);
}