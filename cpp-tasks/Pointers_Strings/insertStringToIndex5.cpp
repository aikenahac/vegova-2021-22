/*
Napiši program, ki na 5. mesto prebranega niza znakov dolžine 20 vstavi prebrani niz dolžine 4. Izpiše naj novi niz.
*/

#include <iostream>
#include <cstring>

void insertTo5(char str[], char str2[]) {
  char *ptr;
  ptr = str;
  for (int i = strlen(str); i > 4; i--) {
    *(ptr + i + strlen(str2)) = *(ptr + i);
  }

  for (int i = 0; i < strlen(str2) - 1; i++) {
    *(ptr + i + 4) = *(str2 + i);
  }
}

int main() {
  char str1[21], str2[5];

  std::cout << "Enter string 1: ";
  fgets(str1, 20, stdin);
  
  std::cout << "Enter string 2: ";
  fgets(str2, 4, stdin);

  insertTo5(str1, str2);
  std::cout << "\n\nNew string: " << str1 << "\n";

  return 0;
}