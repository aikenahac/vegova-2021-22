/*
Napiši program, ki bo v datoteko stevila.txt zapisal 30 naključnih celih števil med 15 in 127.
*/

#include <iostream>
#include <fstream>
#include <ctime>

int main() {
  srand(time(NULL));
  std::ofstream data("stevila.txt", std::ios::app);

  for (int i = 0; i < 30; i++) {
    data << rand() % (127 - 15) + 15 << "\n";
  }

  data.close();
  return 0;
}