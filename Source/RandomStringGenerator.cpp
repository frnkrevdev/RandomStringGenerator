#include "../InputValidation/InputValidation.h"		// For unexpected console inputs
#include "constants.h"
#include "Random.h"									// Self-seeding Mersenne Twister made by Alex from learncpp.com
#include <conio.h>
#include <iostream>
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
	while (true)
	{
		int charNumbers{ numChar() };
		int lineNumbers{ numLines() };

		std::cout << "\nGenerated Strings: \n";

		for (int i{ 1 }; i <= lineNumbers; ++i) {
			std::cout << i << ". ";
			for (int j{ 1 }; j <= charNumbers; ++j) {

				// Using a self-seeding Mersenne Twister PRNG
				std::cout << static_cast<char>(Random::get(startChar, endChar));
			}
			std::cout << "\n";
		}

		std::cout << "\nDo you want to retry? (Press y to retry, Press ANY KEY to quit)...\n";

		// Repeat?
		while (!_kbhit()) {}
		char retry = _getch();

		if (retry == 'y' || retry == 'Y') {
			std::cout << '\n';
			continue;
		}
		break;
	}

	return 0;
}