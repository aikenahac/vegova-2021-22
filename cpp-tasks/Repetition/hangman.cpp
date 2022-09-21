/*
Igro vislice poznamo: Računalnik si izbere naključno besedo in igralec ima omejeno število
poskusov, s katerimi poskuša uganiti posamezno črko. Napiši program v C/C++, ki simulira
malo spremenjeno različico:
    a. Vpiši v program 3 velike črke. Uporabnik (igralec) ima na voljo 6 poskusov. Če
        uporabnik zadene »besedo«, računalnik izpiše besedilo »Zadel si«, v nasprotnem
        primeru pa izpiše besedilo »Obesil si se«.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>

char getRandom() {
    return rand() % (90 - 65 + 1) + 65;
}

std::string generateRandomWord(int wordLength) {
    std::string word;
    for (int i = 0; i < wordLength; i++) {
        word[i] = getRandom();
    }

    return word;
}

int game(std::string word) {
    char guesses[3];
    int charactersFound = 0;
    for (int attemptLoop = 0; attemptLoop < 2; attemptLoop++) {
        std::cout << "Attempt number: " << attemptLoop + 1 << "\n";
        
        for (int i = 0; i < 3; i++) {
            std::cout << "Guess " << i + 1 << ": ";
            std::cin >> guesses[i];
        }

        for (int i = 0; i < 3; i++) {
            if (word.find(guesses[i]) != std::string::npos) {
                charactersFound++;
            }
        }
        std::cout << "\n";

        if (charactersFound == word.length()) {
            std::cout << "Zadel si besedo " << word << "!\n";
            return 0;
        }

        charactersFound = 0;
    }

    if (charactersFound != word.length()) {
        std::cout << "Obesil si se!\n";
    }

    return 0;
}

int main() {
    srand(time(NULL));
    std::string word = generateRandomWord(3);

    game(word);
    return 0;
}