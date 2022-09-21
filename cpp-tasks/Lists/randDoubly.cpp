/*
Dvostransko povezani neurejeni seznam, ki vsebuje naključna cela števila iz intervala (-200, 200].
Izbriši vse večkratnike števila 3 iz intervala [10, 100).
Dodaj funkcijo, ki bere iz dvostranskega in ustvari enostranski urejeni seznam.

rand() % (max_number + 1 - minimum_number) + minimum_number
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

struct DoublyNode {
  int x;
  DoublyNode *next, *prev;
} *head = NULL, *tail = NULL;

struct SingleNode {
  int x;
  SingleNode *next;
} *headS = NULL;

void insert(int a) {
  DoublyNode *tmp = new DoublyNode;

  tmp->x = a;

  if (head == NULL) {
    tmp->next = NULL;
    tmp->prev = NULL;
    head = tmp;
    tail = tmp;
  } else {
    tmp->next = head;
    tmp->prev = NULL;
    head->prev = tmp;
    head = tmp;
  }
}

void print() {
  DoublyNode *tmp = head;

  while (tmp != NULL) {
    std::cout << tmp->x << ", ";
    tmp = tmp->next;
  }
  
  std::cout << "\n";
}

void delete_element(int element) {
  DoublyNode *tmp = head;

  if (head) {
    if (head->x == element) {
      head = head->next;
      delete tmp;
    } else {
      while (tmp->next != NULL && tmp->next->x != element) {
        tmp = tmp->next;
      }
      tmp->next = tmp->next->next;
    }
  }
}

void del_mul_3() {
  DoublyNode *tmp = head;

  while (tmp != NULL) {
    if (tmp->x % 3 == 0 && tmp->x >= 10 && tmp->x <= 100) {
      delete_element(tmp->x);
    }
    tmp = tmp->next;
  }
}

void insert_single(int a) {
  SingleNode *tmp = new SingleNode;

  tmp->x = a;

  if (headS == NULL) {
    tmp->next = NULL;
    headS = tmp;
  } else {
    SingleNode *p = NULL, *c = headS;

    while (c != NULL && c->x < a) {
      p = c;
      c = c->next;
    }

    if (p == NULL) {
      tmp->next = headS;
      headS = tmp;
    } else {
      tmp->next = c;
      p->next = tmp;
    }
  }
}

void doubly_to_single_ordered() {
  DoublyNode *tmp = head;

  while (tmp != NULL) {
    insert_single(tmp->x);
    tmp = tmp->next;
  }
}

int main() {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    insert(rand() % (200 + 1 - (-200)) + (-200));
  }

  std::cout << "List: ";
  print();

  del_mul_3();

  std::cout << "List with removed elements: ";
  print();

  std::cout << "Ordered single list: ";
  doubly_to_single_ordered();
  print();

  return 0;
}