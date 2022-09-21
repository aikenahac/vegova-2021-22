/* 
napiši program, ki prebere niz znakov dolžine največ 15 in najmanj 3. Na 2. mesto vstavi 3 prebrana znaka.
*/

#include <iostream>
#include <cstring>

void read(char *str, int n) {
  std::cout << "Enter a string of length 15 characters: ";
  std::cin.getline(str, n);
}

void insert(char str[], char inserted) {
  char *ptr;
  ptr = str;
  for (int i = strlen(str); i > 0; i--) {
    *(ptr + i + 3) = *(ptr + i);
  }
  str[1] = inserted;
  str[2] = inserted;
  str[3] = inserted;
}

int main() {
  char str[16];
  read(str, 16);
  std::cout << str << "\n";
  insert(str, 'a');
  std::cout << str << "\n";
  return 0;
}