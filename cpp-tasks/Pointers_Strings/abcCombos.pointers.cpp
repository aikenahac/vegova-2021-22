#include <iostream>

int main() {
  char *str = "abc";
  char *p = str;
  while (*p) {
    char *q = p;
    while (*q) {
      char *r = q;
      while (*r) {
        std::cout << *p << *q << *r << "\n";
        r++;
      }
      q++;
    }
    p++;
  }
  return 0;
}