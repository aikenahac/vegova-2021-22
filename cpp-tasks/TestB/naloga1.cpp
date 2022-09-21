/*
Linearni enostranski povezani neurejeni seznam vsebuje podatke o reultatih testa
(ime dijaka, št. točk in ocena). Deklrariraj strukturo in napiši funkcijo, ki:
  a. doda novega dijaka na konec seznama
  b. prešteje, koliko dijakov ima št. točk med a in b (a in b sta argument funkcije) in
    povprečno št. točk negativno ocenjenih dijakov. Podatke izpiše na zaslon.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

struct Test {
  std::string ime_dijaka;
  float st_tock;
  int ocena;
  struct Test *next;
} *start = NULL;

void insert_end(struct Test a) {
  struct Test *tmp = new struct Test;

  tmp->ime_dijaka = a.ime_dijaka;
  tmp->st_tock = a.st_tock;
  tmp->ocena = a.ocena;

  if (start == NULL) {
    tmp->next = NULL;
    start = tmp;
  } else {
    struct Test *c = start;

    while (c->next != NULL) {
      c = c->next;
    }

    c->next = tmp;
    tmp->next = NULL;
  }
}

void points_between(int a, int b) {
  struct Test *tmp = start;
  int ctr = 0;

  while (tmp != NULL) {
    if (tmp->st_tock > a && tmp->st_tock < b) ctr++;
    tmp = tmp->next;
  }

  std::cout << "\nTocke med a in b: " << ctr << "\n";
}


void avg_pts_of_neg() {
  struct Test *tmp = start;

  int count_neg = 0;
  int sum_neg_pts = 0;

  while (tmp != NULL) {
    if (tmp->ocena == 1) {
      count_neg++;
      sum_neg_pts += tmp->st_tock;
    }
    tmp = tmp->next;
  }

  std::cout << "Povprecno st. tock neg: " << sum_neg_pts/count_neg << "\n";
}

void print_list() {
  struct Test *tmp = start;

  while (tmp != NULL) {
    std::cout << "Ime dijaka: " << tmp->ime_dijaka << "\n";
    std::cout << "Ocena: " << tmp->ocena << "\n";
    std::cout << "St. tock: " << tmp->st_tock << "\n\n";
    
    tmp = tmp->next;
  }
}

int main() {
  struct Test x;
  int a = 2, b = 12;

  for (int i = 0; i < 3; i++) {
    std::cin >> x.ime_dijaka;
    std::cin >> x.ocena;
    std::cin >> x.st_tock;
    insert_end(x);
  }

  print_list();

  points_between(a, b);
  avg_pts_of_neg();

  return 0;
}