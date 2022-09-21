/*
Napiši program, ki simulira igro Jackpot:

V igralni aparat vstavi žeton, ki lahko ima vrednost 2.5, 5 ali 7.5 €. Odvisno od vloženega denarja
(žeton) ima igralec določeno število poskusov:

Za 2.5 ima 2 poskusa, za 5 dobi 5 in za 7.5 ima možnost 10krat poskusiti srečo.

Vsakič, ko zažene aparat, se naključno izberejo 3 velike črke od A to T oz. interval [A, T]. Kombinacija
naj se izpiše na zaslon.

Igralec dobi, če so:
    - vse tri črke enake – mali jackpot v vrednosti 3000 €, ki ga potem izplača v kovancih 2.5 in 1 €.
    - vse tri črke so enake črki J – veliki jackpot v vrednosti 5000 €, ki se izplača v kovancih 2.5 in 1€.

Program naj izpiše, koliko kovancev od 1 in 2.5 € je igralec dobil.

A - 65
T - 84
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

char getRandom() {
    return rand() % (84 - 65 + 1) + 65;
}

int insertToken() {
    float token;
    std::cout << "Insert token:\n[2.5€]\n[5.0€]\n[7.5€]\nInsert: ";
    std::cin >> token;

    if (token == 2.5) {
        return 2;
    } else if (token == 5.0) {
        return 5;
    } else if (token == 7.5) {
        return 10;
    } else {
        return 0;
    }
}

int game(int attempts) {
    char x, y, z;
    for (int i = 0; i < attempts; i++) {
        x = getRandom();
        y = getRandom();
        z = getRandom();

        std::cout << "Attempt number: " << i + 1 << "\n";
        std::cout << x << ", " << y << ", " << z << "\n\n";

        if (x == y && y == z) {
            if (x == 'J') {
                return 5000;
            } else {
                return 3000;
            }
        }
    }

    return 0;
}

void payout(int result) {
    int coins25, coins1 = 0;

    switch (result) {
        case 3000:
            std::cout << "Congratulations, you won 3000€!\n\n";
            coins25 = result / 2.5;
            break;
        case 5000:
            std::cout << "Congratulations, you won 5000€!\n\n";
            coins25 = result / 2.5;
            std::cout << "2.5€ coins: " << coins25 << "\n1€ coins: " << coins1 << "\n";
            break;
        default:
            std::cout << "Error in the machine!\n\n";
    }
}


void payout2(int result) {
    int twoFive = result / 2;
    int one = result % 2;
}

int main() {
    srand(time(NULL));
    int attempts, result;

    attempts = insertToken();
    if (attempts == 0) {
        std::cout << "Invalid token, please try again";
        return 0;
    }

    std::cout << "\n\nNumber of attempts: " << attempts << "\n\n";

    result = game(attempts);

    switch (result) {
        case 0:
            std::cout << "Sorry, no reward. Better luck next time!\n\n";
            break;
        case 3000:
            payout(result);
            break;
        case 5000:
            payout(result);
            break;
        default:
            std::cout << "Error in the machine. Try again later!\n\n";
    }

    return 0;
}