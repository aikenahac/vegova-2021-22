#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

void delete_mul(char str[], char *ptr, int pos, int num) {
  for (int i = pos; i <= strlen(str) - num; i++) {
    *(ptr + i) = *(ptr + i + num);
  }
}

void insert_stars(char str[], char c, int pos) {
  char *ptr = str;

  while (*ptr && ptr != str + pos) ++ptr;

  if (ptr == str + pos) {
    do {
      char tmp = *ptr;
      *ptr++ = c;
      c = tmp;
    } while (c);

    *ptr = c;
  }
}

int find_and_del(char str[], int pos, char searched) {
  int num = 0;

  for (int i = pos; i < strlen(str);  i++) {
    if (str[i] == searched) {
      num++;
    }
  }

  return num;
}

int main() {
  char str[101], *ptr = str;
  int pos = 0, num = 0;

  do {
    fgets(str, 101, stdin);
  } while (strlen(str) > 100);

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == str[i+1]) {
      delete_mul(str, ptr, i+1, find_and_del(str, i, str[i]) - 2);
      insert_stars(str, '*', i + 1);
    }
  }

  std::cout << str << "\n";

  return 0;
}