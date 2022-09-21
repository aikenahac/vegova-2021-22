/*
Napišite razred Dijak_matura, ko naj hrani podatke o uspehu dijaka
na maturi (ime_dijaka, SLO, ocena_SLO, MAT, ocena_MAT, ANG, ocena_ANG,
Izb_1, ocena_Izb_1, Izb_2, ocena_Izb_2). Vsi podatki naj bodo zaščiteni
in dostop do njih naj bo izključno preko funkcij. Metoda, ki vrne zaupne
podatke (ocene), naj ima še en parameter (ključ) in naj vrne podatke le
v primeru, če je ključ pravilen.
*/

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

class Dijak_matura {
  private:
    std::string ime_dijaka;
    int slo, mat, ang;
    int izb1, izb2;
    bool access = false;

  public:
    Dijak_matura(std::string key) {
      if (key == "yourmomisfat") {
        access = true;
      }
    }
    int get_slo() {
      if (!access) return -1;
      return slo;
    }
    int get_mat() {
      if (!access) return -1;
      return mat;
    }
    int get_ang() {
      if (!access) return -1;
      return mat;
    }
    int get_izb1() {
      if (!access) return -1;
      return mat;
    }
    int get_izb2() {
      if (!access) return -1;
      return mat;
    }
    void setData() {
      std::cout << "Vnesi ime dijaka: ";
      std::cin >> ime_dijaka;
      slo = rand() % 5 + 1;
      mat = rand() % 5 + 1;
      ang = rand() % 5 + 1;
      izb1 = rand() % 5 + 1;
      izb2 = rand() % 5 + 1;
    }
    void getData(std::string key) {
      if (!access) std::cout << "Nimaš dostopa!" << "\n";
      else {
        std::cout << "Ime dijaka: " << ime_dijaka << std::endl;
        std::cout << "Slo: " << slo << std::endl;
        std::cout << "Mat: " << mat << std::endl;
        std::cout << "Ang: " << ang << std::endl;
        std::cout << "Izb_1: " << izb1 << std::endl;
        std::cout << "Izb_2: " << izb2 << std::endl;
      }
    }
};

int main() {
  Dijak_matura dijak("yourmomisfat");
  std::string key;

  dijak.setData();

  std::cin.ignore();

  std::cout << "Enter the access key: ";
  std::cin >> key;
  
  system(CLEAR);

  dijak.getData(key);

  return 0;
}