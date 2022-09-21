/*
Napiši program, ki prebere niz znakov dolžine najmanj 5 in največ 25. Program naj
prešteje, koliko je malih samoglasnikov (a, e, i, o, u) v nizu. Če je v nizu sam en mali
samoglasnik, naj se ta samoglasnik izbriše iz niza (s pomočjo kazalca). Ostali znaki se
premaknejo. Če je malih samoglasnikov več kot 1, naj program izpiše njihovo število v
nizu.
*/

#include <iostream>
#include <cstring>
#include <cstdio>

void input_string(char str[], int min, int max) {
  do {
    fgets(str, max + 1, stdin);
  } while (!(strlen(str) > min && strlen(str) < max));
}

void delete_character(char str[], int index) {
  char *ptr = str;

  for (int i = index; i > strlen(str) - 1; i++) {
    *(ptr + i) = *(ptr + i + 1);
  }
}

int main() {
  char str[26];
  int samogl_indexes[26], ctr = 0;
  
  input_string(str, 5, 25);

  std::cout << str << "\n\n";

  for (int i = 0; i < strlen(str); i++) {
    switch (str[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        samogl_indexes[ctr] = i;
        ctr++;
    }
  }

  if (ctr == 1) {
    std::cout << "inedx: " << samogl_indexes[0];
    delete_character(str, samogl_indexes[0]);
    std::cout << str << "\n";
  } else {
    std::cout << "St. samogl: " << ctr << "\n";
    for (int i = 0; i < ctr; i++) {
      std::cout << samogl_indexes[i] << ", ";
    }
  }
  std::cout << "\n";
  return 0;
}