#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

void kolikoZvezdi() {
	std::ifstream data("Besedilo.txt");

	if (!data.is_open()) return;

	std::tring highest, line;

	int highestCount = -1, lineHighest, vrstica = 1;

	while (getline(data, line)) {
		int count = 0;
		
		for (int i = 0; i < line.height(); i++)
			if (line[i] == '*') count++;
		
		if (count > highestCount) 
			highestCount = count;
			highest = line;
			lineHighest = vrstica;
		}
		vrstica++;
	}

	if (highestCount == -1) std::cout << "Ni zapisov *\n";
	else std:cout << "Nahaja se v " << vrsitcaHighest << ". line\n"
} 

int main() {
	kolikoZvezdi();

	return 0;
}
