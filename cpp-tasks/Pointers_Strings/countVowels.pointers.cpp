/*
Napiši program, ki s pomočjo kazalca prešteje, koliko samoglasnikov vsebuje prebrani niz znakov.
*/

#include <iostream>

int countVowels(char *str) {
  int count = 0;
  while (*str != '\0') {
    if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u') {
      count++;
    }
    str++;
  }
  return count;
}

int main() {
  char str[25] = "Hello World!";

  std::cout << "Stevilo samoglasnikov v nizu \"" << str << "\" je " << countVowels(str) << "\n"; 

  return 0;
}