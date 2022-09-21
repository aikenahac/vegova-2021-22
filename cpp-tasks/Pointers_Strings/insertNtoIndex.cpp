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
  char string[20] = "Hello World";
  char c;
  int index;
  
  std::cout << string << "\n\n";
  
  std::cout << "Input a character: ";
  std::cin >> c;
  std::cout << "Input an index: ";
  std::cin >> index;
  std::cout << addLetter(string, c, index) << "\n";

  return 0;
}