/*
Ustvari binarno datoteko dijaki.bin, ki bo vsebovala podatke o dijakih (priimek, visina).
Podatki naj se ob vpisu vpisujejo tako, da bo datoteka sortirana padajoce.
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

struct Dijak {
  char priimek[20];
  float visina;
};

int main() {
  std::ofstream data("dijaki.bin", std::ios::binary | std::ios::app);

  std::vector<Dijak> dijaki;

  bool get_input = true;
  char continue_input;

  while (get_input) {

    std::cout << "Add another student? [y/n]: ";
    std::cin >> continue_input;
    if (continue_input == 'n') get_input = false;
  }

  return 0;
}