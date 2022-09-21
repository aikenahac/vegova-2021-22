/*
Napiši program, ki v prebrani niz znakov dolžine 20 vstavi znak a na 10. mesto in izpiše novi niz (uporabi kazalce).
*/
#include <iostream>
#include <string>

int main() {
  char* str = "Inserting a char ye.";
  char c = '!';
  int index = 10;

  std::cout << "Before: " << str << "\n";

  for (int i = 20; i >= index; i--) {
    str[i] = str[i - 1];
  }
  str[index] = c;

  std::cout << "After: " << str << "\n";

  return 0;
}