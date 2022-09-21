#include <Arduino.h>
#include "DHT.h"
#define DHTPIN 2     // Digital pin (vhod)za DHT sensor
#define DHTTYPE DHT11   // DHT 11
const int digitPins[4] = {
  4,5,6,7};                 //4 skupne katode 7 seg. prikazovalnik
const int clockPin = 11;    //74HC595 Pin 11 
const int latchPin = 12;    //74HC595 Pin 12
const int dataPin = 13;     //74HC595 Pin 14
const byte digit[10] =      //bitni zapis številke na 7 seg. prikazovalniku
{
  B00111111, //0
  B00000110, //1
  B01011011, //2
  B01001111, //3
  B01100110, //4
  B01101101, //5
  B01111101, //6
  B00000111, //7
  B01111111, //8
  B01101111  //9
};
int digitBuffer[4] = {
  0};
int digitScan = 0;
;
float t;

DHT dht(DHTPIN, DHTTYPE);
 
void setup(){ 
dht.begin();
Serial.begin(9600);   //serijski port za kontrolo delovanja algoritma            
  for(int i=0;i<4;i++)
  {
    pinMode(digitPins[i],OUTPUT);  //štirje pini za skupne katode
  }
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
}
 
//zapis temperature na 7 seg. 4 številčnem prikazovalniku
void updateDisp(){
  for(byte j=0; j<4; j++)  
    digitalWrite(digitPins[j], HIGH);   // ugasnemo vse štiri številke
 
  digitalWrite(latchPin, LOW);  
  shiftOut(dataPin, clockPin, MSBFIRST, B11111111);
  digitalWrite(latchPin, HIGH);
 
  delayMicroseconds(100);
  digitalWrite(digitPins[digitScan], LOW);
 
  digitalWrite(latchPin, LOW);  
  if(digitScan==2)
    shiftOut(dataPin, clockPin, MSBFIRST, (digit[digitBuffer[digitScan]] | B10000000)); //aktiviramo decimalno piko na tretji številki
  else
    shiftOut(dataPin, clockPin, MSBFIRST, digit[digitBuffer[digitScan]]);
  digitalWrite(latchPin, HIGH);
  digitScan++;
  if(digitScan>3) digitScan=0; 
} 

void loop(){ 
// Preberemo temperaturo v Celzijevih stopinjah
  float t = dht.readTemperature();  
  Serial.println(t);
  t = int(t*100);
  digitBuffer[3] = int(t)/1000;
  digitBuffer[2] = (int(t)%1000)/100;
  digitBuffer[1] = (int(t)%100)/10;
  digitBuffer[0] = (int(t)%100)%10;
  updateDisp();
  delay(2);
 //Serial.println (t);
 //Serial.println (digitBuffer[3]);
 //Serial.println (digitBuffer[2]);
 //Serial.println (digitBuffer[1]);
 //Serial.println (digitBuffer[0]);
}
