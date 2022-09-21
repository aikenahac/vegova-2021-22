#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

struct Data {
  std::string letni_cas; // pomlad, poletje, jesen, zima
  float temp;
  float snow_height;
};

struct Node {
  struct Data data;

  struct Node *next, *prev;
} *head = NULL, *tail = NULL;

struct SpringSummer {
  struct Data data;
  struct SpringSummer *next, *prev;
} *headSS = NULL, *tailSS = NULL;

struct FallWinter {
  struct Data data;
  struct FallWinter *next, *prev;
} *headFW = NULL, *tailFW = NULL;

void insert(struct Data data) {
  struct Node *tmp = new struct Node;

  tmp->data = data;

  if (head == NULL) {
    tmp->next = NULL;
    tmp->prev = NULL;
    head = tmp;
    tail = tmp;
  } else {
    tmp->prev = tail;
    tail->next = tmp;
    tmp->next = NULL;
    tail = tmp;
  }
}

void insert_ss(struct Data data) {
  struct SpringSummer *tmp = new struct SpringSummer;

  tmp->data = data;

  if (headSS == NULL) {
    headSS = tmp;
    tailSS = tmp;
    tmp->next = NULL;
    tmp->prev = NULL;
  } else {
    struct SpringSummer *p = NULL, *c = headSS;

    while (c != NULL && c->data.temp < tmp->data.temp) {
      p = c;
      c = c->next;
    }

    if (c == headSS) {
      tmp->next = headSS;
      tmp->prev = NULL;
      headSS->prev = tmp;
      headSS = tmp;
    } else if (c == NULL) {
      tmp->prev = tailSS;
      tmp->next = NULL;
      tailSS->next = tmp;
      tailSS = tmp;
    } else {
      tmp->prev = p;
      tmp->next = c;
      p->next = tmp;
      c->prev = tmp;
    }
  }
}

void insert_fw(struct Data data) {
  struct FallWinter *tmp = new struct FallWinter;

  tmp->data = data;

  if (headFW == NULL) {
    headFW = tmp;
    tailFW = tmp;
    tmp->next = NULL;
    tmp->prev = NULL;
  } else {
    struct FallWinter *p = NULL, *c = headFW;

    while (c != NULL && c->data.temp < tmp->data.temp) {
      p = c;
      c = c->next;
    }

    if (c == headFW) {
      tmp->next = headFW;
      tmp->prev = NULL;
      headFW->prev = tmp;
      headFW = tmp;
    } else if (c == NULL) {
      tmp->prev = tailFW;
      tmp->next = NULL;
      tailFW->next = tmp;
      tailFW = tmp;
    } else {
      tmp->prev = p;
      tmp->next = c;
      p->next = tmp;
      c->prev = tmp;
    }
  }
}

void sort_el() {
  struct Node *tmp = head;

  while (tmp != NULL) {
    if (tmp->data.letni_cas == "poletje" || tmp->data.letni_cas == "pomlad") {
      insert_ss(tmp->data);
    } else if (tmp->data.letni_cas == "jesen" || tmp->data.letni_cas == "zima") {
      insert_fw(tmp->data);
    }

    tmp = tmp->next;
  }
}

void find_incorrect_ss() {
  struct SpringSummer *tmp = headSS, *p = NULL, *c = headSS;

  while (tmp != NULL) {
    if (tmp->data.letni_cas == "zima" || tmp->data.letni_cas == "jesen") {
      insert_fw(tmp->data);
      if (c == headSS) {
        if (headSS == tailSS) {
          headSS = NULL;
          tailSS = NULL;
        } else {
          headSS = headSS->next;
          headSS->prev = NULL;
        }
      } else if (c->next == NULL) {
        tailSS = tailSS->prev;
        tailSS->next = NULL;
      } else {
        p->next = c->next;
        p->next->prev = p;
      }

      delete c;
    }

    c = tmp;
    p = c->prev;

    tmp = tmp->next;
  }
}

void find_incorrect_fw() {
  struct FallWinter *tmp = headFW, *p = NULL, *c = headFW;

  while (tmp != NULL) {
    if (tmp->data.letni_cas == "poletje" || tmp->data.letni_cas == "pomlad") {
      insert_ss(tmp->data);
      if (c == headFW) {
        if (headFW == tailFW) {
          headFW = NULL;
          tailFW = NULL;
        } else {
          headFW = headFW->next;
          headFW->prev = NULL;
        }
      } else if (c->next == NULL) {
        tailFW = tailFW->prev;
        tailFW->next = NULL;
      } else {
        p->next = c->next;
        p->next->prev = p;
      }

      delete c;
    }

    c = tmp;
    p = c->prev;

    tmp = tmp->next;
  }
}

void print() {
  struct Node *tmp = head;

  while (tmp != NULL) {
    std::cout << tmp->data.letni_cas << "\n";
    std::cout << tmp->data.snow_height << "cm\n";
    std::cout << tmp->data.temp << "degC\n\n";

    tmp = tmp->next;
  }

  std::cout << "\n";
}

void print_ss() {
  struct SpringSummer *tmp = headSS;

  while (tmp != NULL) {
    std::cout << tmp->data.letni_cas << "\n";
    std::cout << tmp->data.snow_height << "cm\n";
    std::cout << tmp->data.temp << "degC\n\n";

    tmp = tmp->next;
  }

  std::cout << "\n";
}

void print_fw() {
  struct FallWinter *tmp = headFW;

  while (tmp != NULL) {
    std::cout << tmp->data.letni_cas << "\n";
    std::cout << tmp->data.snow_height << "cm\n";
    std::cout << tmp->data.temp << "degC\n\n";

    tmp = tmp->next;
  }

  std::cout << "\n";
}

void print_rev() {
  struct Node *tmp = tail;

  while (tmp != NULL) {
    std::cout << tmp->data.letni_cas << "\n";
    std::cout << tmp->data.snow_height << "cm\n";
    std::cout << tmp->data.temp << "degC\n\n";

    tmp = tmp->prev;
  }

  std::cout << "\n";
}

void find_max_ss(std::string letni_cas) {
  struct SpringSummer *tmp = headSS;
  struct SpringSummer *max_sh_el = new struct SpringSummer;

  max_sh_el->data.snow_height = 0;

  while (tmp != NULL) {

    if (tmp->data.letni_cas == letni_cas && max_sh_el->data.snow_height < tmp->data.snow_height) {
      max_sh_el = tmp;
    }

    tmp = tmp->next;
  }

  std::cout << "Najvec snega:\n";
  std::cout << "Letni cas: " << max_sh_el->data.letni_cas << "\n";
  std::cout << "Temperatura: " << max_sh_el->data.temp << "\n";
  std::cout << "Visina snega: " << max_sh_el->data.snow_height << "\n\n";
}

void find_max_fw(std::string letni_cas) {
  struct FallWinter *tmp = headFW;
  struct FallWinter *max_sh_el = new struct FallWinter;

  max_sh_el->data.snow_height = 0;

  while (tmp != NULL) {

    if (tmp->data.letni_cas == letni_cas && max_sh_el->data.snow_height < tmp->data.snow_height) {
      max_sh_el = tmp;
    }

    tmp = tmp->next;
  }

  std::cout << "Najvec snega:\n";
  std::cout << "Letni cas: " << max_sh_el->data.letni_cas << "\n";
  std::cout << "Temperatura: " << max_sh_el->data.temp << "\n";
  std::cout << "Visina snega: " << max_sh_el->data.snow_height << "\n\n";
}

int main() {

  for (int i = 0; i < 5; i++) {
    struct Data tmp;

    std::cout << "Enter data:\n";
    std::cin >> tmp.letni_cas;
    std::cin >> tmp.snow_height;
    std::cin >> tmp.temp;
    std::cout << "\n\n";
    
    insert(tmp);
  }

  // Doda v sezname
  sort_el();

  bool running = true;
  int selection;
  std::string letni_cas;
  std::cout << "Izbira:\n[0] Izpisi vse\n[1] Izpis vse reverse\n[2] Poisci napacne v SpringSummer\n[3] Poisci napacne v FallWinter\n[4] Poisci najvecjega za prebrani letni cas\n[5] Izpisi SpringSummmer\n[6] Izpisi FallWinter\n[7] Koncaj\nVpisi: ";
  std::cin >> selection;

  switch (selection) {
    case 0:
      print();
      break;
    case 1:
      print_rev();
      break;
    case 2:
      find_incorrect_ss();
      print_ss();
      print_fw();
      break;
    case 3:
      find_incorrect_fw();
      print_ss();
      print_fw();
      break;
    case 4:
      std::cout << "Vpisi iskani letni cas: ";
      std::cin >> letni_cas;
      if (letni_cas == "poletje" || letni_cas == "pomlad") find_max_ss(letni_cas);
      else if (letni_cas == "jesen" || letni_cas == "zima") find_max_fw(letni_cas);
      break;
    case 5:
      print_ss();
      break;
    case 6:
      print_fw();
      break;
    case 7:
      running = false;
      break;
    default:
      std::cout << "Neveljavna opcija!\n\n";
  }

  return 0;
}