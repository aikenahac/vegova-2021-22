/*
Na ravni EU se zbirajo podatki o koroni: ime države, število okuženih in procent cepljenih.
  a. Napiši C/C++ funkcijo, ki ustvari dvostransko povezani urejeni (abecedno po imenu države)
    kazalčni seznam
  b. Dodaj funkcijo, ki iz seznama izbriše podatek o državi z najmanjšim številom okuženih.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

struct Country {
  std::string name;
  int infected;
  float vaccinated;
  struct Country *next;
  struct Country *prev;
} *start = NULL, *tail = NULL;

void insert(struct Country a) {
  struct Country *tmp = new struct Country;

  tmp->name = a.name;
  tmp->infected = a.infected;
  tmp->vaccinated = a.vaccinated;

  if (start == NULL) {
    tmp->next = NULL;
    tmp->prev = NULL;
    start = tmp;
    tail = tmp;
  } else {
    struct Country *p = NULL, *c = start;

    while (c != NULL && c->name < a.name) {
      p = c;
      c = c->next;
    }

    if (p == NULL) {
      tmp->next = start;
      tmp->prev = NULL;
      start->prev = tmp;
      start = tmp;
    } else if (c == NULL) {
      tmp->prev = tail;
      tmp->next = NULL;
      tail->next = tmp;
      tail = tmp; 
    } else {
      p->next = tmp;
      c->prev = tmp;
      tmp->prev = p;
      tmp->next = c;
    }
  }
}

void del_min_infected() {
  struct Country *tmp = start, *p = NULL, *c = start;

  int min_infected = start->infected;

  while (tmp != NULL) {
    if (min_infected > tmp->infected) {
      min_infected = tmp->infected;
      c = tmp;
      p = c->prev;
    }
    tmp = tmp->next;
  }

  if (c == start) {
    if (start == tail) {
      start = NULL;
      tail = NULL;
    } else {
      start = start->next;
      start->prev = NULL;
    }
  } else if (c->next == NULL) {
    tail = tail->prev;
    tail->next = NULL;
  } else {
    p->next = c->next;
    p->next->prev = p;
  }
  delete c;
}

void print_list() {
  struct Country *tmp = start;

  while (tmp != NULL) {
    std::cout << "Drzava: " << tmp->name << "\n";
    std::cout << "St. okuzenih: " << tmp->infected << "\n";
    std::cout << "% cepljenih: " << tmp->vaccinated << "\n\n";

    tmp = tmp->next;
  }
}

int main() {
  struct Country x;

  for (int i = 0; i < 3; i++) {
    std::cin >> x.name;
    std::cin >> x.infected;
    std::cin >> x.vaccinated;

    insert(x);
  }

  print_list();
  del_min_infected();
  std::cout << "\n\n";
  print_list();

  return 0;
}