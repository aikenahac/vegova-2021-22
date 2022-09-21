/*
Napiši program, ki prebere dva niza znakov.
Prvi niz naj bo dolžine najmanj 5 največ 15, drugi niz dolžine najmanj 2 največ 5 znakov.

Program naj drugi niz vstavi na četrto mesto prvega niza.
*/
#include <iostream>
#include <cstring>

void readString(char str[], int minLen, int maxLen) {
  do {
    fgets(str, maxLen, stdin);
  } while (strlen(str) < minLen || strlen(str) > maxLen);
}

void insert(char str[], char str2[]) {
  char *ptr;
  ptr = str;
  for (int i = strlen(str); i > 2; i--) {
    *(ptr + i + strlen(str2)) = *(ptr + i);
  }

  for (int i = 0; i < strlen(str2); i++) {
    *(ptr + i + 3) = *(str2 + i);
  }
}

int main() {
  char str1[16], str2[6];

  readString(str1, 5, 15);
  readString(str2, 2, 5);

  std::cout << "Strings: " << str1 << str2;

  insert(str1, str2);
  std::cout << "\n\nYoo: " << str1 << "\n";

  return 0;
}