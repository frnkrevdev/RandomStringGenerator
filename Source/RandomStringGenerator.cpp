#include "../InputValidation/InputValidation.h"		// Library for unexpected console inputs
#include "Random.h"									// Self-seeding Mersenne Twister made by Alex from learncpp.com
#include <iostream>
#include <limits>
#include <string>

// Function that let the user enter the number of characters to be generated
int numChar()
{
	while (true){
		std::cout << "Enter number of characters to be generated: ";
		int numChar{};
		std::cin >> numChar;

		// Input validation
		if (inputInvalid()) {
			continue;
		}
		if (numChar <= 1 ) {
			std::cout << "Error! A string must be greater than 1 character.\n";
			continue;
		}

		return numChar;
	}
}

// Function that let the user enter the number of lines to be generated
int numLines()
{
	while (true){
		std::cout << "Enter number of lines to be generated: ";
		int numLines{};
		std::cin >> numLines;

		// Input validation
		if (inputInvalid()) {
			continue;
		}
		if (numLines <= 0) {
			std::cout << "Error! There must be at least 1 line.\n";
			continue;
		}

		return numLines;
	}
}

int main()
{
	int charNumbers{ numChar() };
	int lineNumbers{ numLines() };

	std::cout << "\nGenerated Strings: \n";

	for (int i{ 1 }; i <= lineNumbers; ++i) {
		std::cout << i << ". ";
		for (int j{ 1 }; j <= charNumbers; ++j) {

			// Using a self-seeding Mersenne Twister PRNG
			std::cout << static_cast<char>(Random::get(33, 126));	
		}
		std::cout << '\n';
	}

	return 0;
}