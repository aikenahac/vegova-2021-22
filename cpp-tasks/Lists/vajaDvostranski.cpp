/*
Ustvari dvostransko povezani urejeni seznam ki vsebuje nakljucna cela stevila iz intervala med -100 in 100.

Dodaj funkcijo, ki zbriše prebrano število.

Dodaj funkcijo, ki zbriše vsa števila med -10 in 30.
*/

#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>

struct El {
  int x;
  El *prev, *next;
} *start = NULL, *endl = NULL;

void insert(int a) {
  El *tmp = new El;
  tmp->x = a;

  if (start == NULL) {
    start = tmp;
    endl = tmp;
    tmp->next = NULL;
    tmp->prev = NULL;
  } else {
    El *p = NULL, *c=start;
    
    while (c != NULL && c->x < tmp->x) {
      p = c;
      c = c->next;
    }

    if (c == start) {
      tmp->next = start;
      tmp->prev = NULL;
      start->prev = tmp;
      start = tmp;
    } else if (c == NULL) {
      tmp->prev = endl;
      tmp->next = NULL;
      endl->next = tmp;
      endl = tmp;
    } else {
      tmp->prev = p;
      tmp->next = c;
      p->next = tmp;
      c->prev = tmp;
    }
  }
}

void removeRead(int a) {
  if (start != NULL) {
    El *p = start;
    
    while (p != NULL && p->x != a) {
      p = p->next;
    }

    if (p != NULL) {
      p->prev->next = p->next;

      if (p->next != NULL) {
        p->next->prev = p->prev;
      }

      delete p;
    }
    
  }
}

void removeRange(int rStart, int rEnd) {
  El *p = start, *rm_st;

  while (p != NULL && p->x < rEnd) {
    p = p->next;

    if (p != NULL) delete p->prev;
  }

  p->prev = rm_st->prev;
  rm_st->prev->next = p;
}

void print() {
  El *p = start;

  std::cout << p->x;
  p = p->next;

  while (p != NULL) {
    std::cout << ", " << p->x;
    p = p->next;
  }

  std::cout << "\n";
}

int main() {
  srand(time(NULL));
  
  for (int i = 0; i < 10; i++) {
    insert(rand()%((100 + 99) - 99)); 
  }
}