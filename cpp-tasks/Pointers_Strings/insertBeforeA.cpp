/*
Napiši program, ki prebere niz znakov dolžine najmanj 3 največ 15 in drugi niz znakov dolžine točno 4 znake.
Poišči prvo pojavljanje črke a in pred njo vstavi drugi niz.
Izbriši vse samoglasnike. 
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

void inputString(char str[], int min, int max) {
  do {
    fgets(str, max + 1, stdin);
  } while (!(strlen(str) >= min && strlen(str) <= max));
}

int findA(char str[]) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'a' || str[i] == 'A') {
      return i;
    }
  }
  return -1;
}

void insertBeforeA(char str1[], char str2[]) {
  char *ptr;
  ptr = str1;

  int index = findA(str1);

  for (int i = strlen(str1); i > index; i--) {
    *(ptr + i + strlen(str2)) = *(ptr + i);
  }

  for (int i = 0; i < strlen(str2) - 1; i++) {
    *(ptr + i + index) = *(str2 + i);
  }
}

int main() {
  char str1[16], str2[5];
  char str_merged[25];

  std::cout << "Enter first string: ";
  inputString(str1, 3, 15);
  fflush(stdin);
  std::cout << "Enter second string: ";
  inputString(str2, 4, 4);

  std::cout << "\n";

  std::cout << "Vpisano: " << str1;
  std::cout << "Vpisano: " << str2 << "\n";

  strcpy(str_merged, str1);
  insertBeforeA(str_merged, str2);
  std::cout << "Merged string: " << str_merged << "\n";
  return 0;
}