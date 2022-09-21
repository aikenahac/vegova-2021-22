/*
Napiši program, ki deklarira razred Racunanje, ki naj vsebuje realno število a, konstruktor, destruktor ter
tri preobložene metode Racun (). Prva metoda Racun naj ne vsebuje vhodnih podatkov in naj vrne kvadrat števila
a. Druga metoda Racun naj vsebuje vhodni podatek b, in naj vrne zmnožek a in b. Tretja metoda naj vsebuje tudi
en vhodni podatek n in naj izračuna in vrne potenco an. V glavnem programu ustvari objekt razreda Racunanje
ter klici vse njegove metode.
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>

class Racunanje {
  private:
    float a;

  public:
    Racunanje();
    float Racun();
    float Racun(float b);
    float Racun(int n);
    ~Racunanje();
};

Racunanje::Racunanje() {
  a = 6.0;
}

float Racunanje::Racun() {
  return a * a;
}

float Racunanje::Racun(float b) {
  return a * b;
}

float Racunanje::Racun(int n) {
  int result = 1;

  for (int i = 0; i < n; i++) {
    result *= a;
    return a;
  }
}

Racunanje::~Racunanje() {}

int main() {
  Racunanje x;

  x.Racun();

  x.Racun(3);

  x.Racun(2);

  return 0;
}