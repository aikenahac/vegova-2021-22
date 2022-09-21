/*
Primeri, na katerih program mora delati, se nahajajo na koncu navodil

Napiši program v C/C++, ki prebere neko poved dolžine 50 znakov.
    a. S pomočjo funkcije Isci() poišče zadnjo besedo v besedilu in jo izpiše.
    b. Dodaj funkcijo, ki bo izpisala, katera beseda v povedi se začne na be, Be
        ali BE.
    c. Dodaj funkcijo, ki celo besedilo sortira po abecedi.
    d. Z binarnim iskanjem poišči prebrani znak.
    e. Izpiši najdaljšo besedo
    f. Vsako besedo dodaj v tabelo in sortiraj besede po abecedi.

Primeri:
Locílo je znak v besedilu, ki ni crka,  stevilka ..
    a. zadnja beseda je stevilka
    b. Besede, ki se začne na BE, je besedilu.

Stevke, crke, posebni znaki – vse so ASCII znaki..
    a. zadnja beseda je znaki
    b. Besede, ki se začne na BE, NI v besedilu.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

bool isBe(std::string word) {
    std::string firstTwoChars = word.substr(0, 2);

    if (firstTwoChars == "Be" || firstTwoChars == "be" || firstTwoChars == "BE" || firstTwoChars == "bE") {
        return true;
    } else {
        return false;
    }
}

void Isci(std::string besedilo) {
    int i = besedilo.length() - 1;

    while (i != 0 && !isspace(besedilo[i])) i--;

    std::string finalWord = besedilo.substr(i+1);

    std::cout << "Zadnja beseda v besedilu je: " << finalWord << std::endl;
}

void sortAllByABC(std::string besedilo) {
    for(int i = 0; i < besedilo.length(); i++){
        for(int j = i + 1; j < besedilo.length(); j++){
            if (besedilo[j] < besedilo[i]) {
                char temp = besedilo[i];
                besedilo[i] = besedilo[j];
                besedilo[j] = temp;
            }
        }
    }

    besedilo.erase(std::remove_if(besedilo.begin(), besedilo.end(), isspace));

    std::cout << "Sorted by ABC: " << besedilo << "\n";
}

void findBE(std::string besedilo) {
    std::vector<std::string> words;
    std::vector<std::string> wordsBeginWithBe;

    std::string temp = "";

    for (int i=0; i < besedilo.length(); i++) {
        if (besedilo[i] == ' ') {
            words.push_back(temp);
            temp = "";
        } else {
            temp.push_back(besedilo[i]);
        }
    }

    for (const auto &str : words) {
        if (isBe(str)) {
            wordsBeginWithBe.push_back(str);
        }
    }

    for (const auto &str : wordsBeginWithBe) {
        std::cout << "Besede, ki se začnejo na BE: " << str << std::endl;
    }
}

std::string findLogestWord(std::string besedilo) {
    std::vector<std::string> words;
    std::string temp = "";

    for (int i=0; i < besedilo.length(); i++) {
        if (besedilo[i] == ' ') {
            words.push_back(temp);
            temp = "";
        } else {
            temp.push_back(besedilo[i]);
        }
    }

    words.push_back(temp);

    std::string longest = "";
    for (const auto &str : words) {
        if (str.length() > longest.length()) {
            longest = str;
        }
    }

    return longest;
}

void sortWordsByABC(std::string besedilo) {
    std::vector<std::string> words;

    std::string temp = "";

    for (int i = 0; i < besedilo.length(); i++) {
        if (besedilo[i] == ' ') {
            words.push_back(temp);
            temp = "";
        } else {
            temp.push_back(besedilo[i]);
        }
    }

    words.push_back(temp);

    std::sort(words.begin(), words.end());

    for (const auto &str : words) {
        std::cout << str << "\n";
    }
}

int main() {
    std::string besedilo{"this is a besedilo in which supercaifragilisticexpialidocious i need to find the last word."};

    Isci(besedilo);

    sortWordsByABC(besedilo);

    return 0;
}