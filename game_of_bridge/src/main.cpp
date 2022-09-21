#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>

struct Card {
  int value; // 1-13
  char suit; // S - spades, H - hearts, D - diamonds, C - clubs
};

void create_deck(std::vector<Card> &pack) {
  for (int i = 1; i < 52; i++) {
    Card card;
    card.value = (rand() % 10) + 1;
    int randNum = (rand() % 4);
    
    switch (randNum) {
      case 0:
        card.suit = 'S';
        break;
      case 1:
        card.suit = 'H';
        break;
      case 2:
        card.suit = 'D';
        break;
      case 3:
        card.suit = 'C';
        break;
    }
  }
}

void deal_cards(std::vector<Card> &pack, std::vector<std::vector<Card>> &hands) {
  // Go through each hand and deal 13 cards
  for (int i = 0; i < 4; i++) {
    // Go through each card in the pack and choose one
    for (int i = 0; i < 13; i++) {
      hands[i].push_back(pack[i]);
      pack.erase(pack.begin() + i);
    }
  }
}

void print_deck(std::vector<std::vector<Card>> &hands) {
  for (int i = 0; i < 4; i++) {
    std::cout << "Hand " << i + 1 << " cards:\n";
    for (int j = 0; j < 13; j++) {
      if (j == 0) {
        std::cout << "|_" << hands[i][j].value << " " << hands[i][j].suit << "\n";
      } else {
        std::cout << "_" << hands[i][j].value << " " << hands[i][j].suit << "\n";
      }
    }
    std::cout << "\n\n";
  }
}

int main() {
  const int no_of_players = 4;

  std::vector<Card> pack(52);
  std::vector<std::vector<Card>> hands(no_of_players);

  // Create a deck of cards
  create_deck(pack);

  // Shuffle the deck
  std::random_shuffle(pack.begin(), pack.end());

  // Deal the cards
  deal_cards(pack, hands);

  return 0;
}