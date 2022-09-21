/*
Deklariraj niz beseda, ki naj vsebuje največ 20 znakov.
Vrednost niza vnesi s tipkovnice ter s pomočjo kazalca
na niz omogoči dodajanje znakov (brez uporabe že
napisanih metod ali funkcij) v niz beseda,
na n-to mesto.

Primer:
  • beseda: Puto , vstavljanje na 3. mesto, črka 'n': Punto
*/

#include <iostream>

char * addLetter(char string[], char c, int pos ) {
  char *ptr = string;

  while (*ptr && ptr != string + pos) ++ptr;

  if (ptr == string + pos ) {
    do {
      char tmp = *ptr;
      *ptr++ = c;
      c = tmp;
    } while (c);

    *ptr = c;
  }

  return string;
}

int main() {
  char string[20];
  char c;
  int index;
  
  std::cout << "Enter a string: ";
  fgets(string, 20, stdin);
  
  std::cout << "Input a character: ";
  std::cin >> c;
  std::cout << "Input an index: ";
  std::cin >> index;
  std::cout << addLetter(string, c, index) << "\n";

  return 0;
}