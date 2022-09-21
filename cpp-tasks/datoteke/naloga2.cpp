/*
Napiši program, ki iz datoteke stevila.txt izpiše na zaslon vse velike črke (od 65 do 91).
*/

#include <iostream>
#include <fstream>

int main() {
  std::ifstream data("stevila.txt");
  std::string line;

  if (data.is_open()) {
    while (getline(data, line)) {
      int int_line = std::stoi(line);
      if (int_line >= 65 && int_line <= 91) {
        std::cout << char(int_line) << "\n";
      }
    }
    data.close();
  } else std::cout << "Unable to open file.";

  return 0;
}