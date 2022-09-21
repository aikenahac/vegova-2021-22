/*
Napiši program, ki iz prebranega niza znakov dolžine 25 izbriše 5,6 in 7. znak ter izpiše novi niz.
*/

#include <iostream>
#include <cstring>

void del567(char str[]) {
  char *ptr;
  ptr = str;

  for (int i = 4; i < strlen(str) - 1; i++) {
    *(ptr + i) = *(ptr + i + 3);
  }
}

int main() {
  char str[26];
  fgets(str, 25, stdin);
  std::cout << str << "\n";
  del567(str);
  std::cout << str << "\n";
  return 0;
}