#include <iostream>
#include "helpers.cpp"

int main(int argc, char** argv) {
    int currentValue;
    int randNumber = 0;
    std::string userName; 
    if (argc >= 2) {
        std::string _n = argv[1];
        const char* ptr2 = argv[2];
        int maxVal = std::strtoul(ptr2, nullptr, 0);
        if ( _n == "-max" &&  maxVal ) {
            randNumber = getRandomValue(maxVal);
        }
    }
    else {
        randNumber = getRandomValue();
    } 
    userName = getUserName();
    std::cout << "Enter your guess:" << std::endl;
    int i = 1;
	do {
		std::cin >> currentValue;

		if (currentValue > randNumber) {
			std::cout << "less than " << currentValue << std::endl;
		}
		else if (currentValue < randNumber) {
			std::cout << "greater than " << currentValue << std::endl;
		}
		else {
			std::cout << "You win, " << userName << ", in " << i << " attempts" << std::endl;
			break;
		}
        ++i;
	} while(true);
    if (writeScore(userName, i)) {    
        pretty_printer("Score recorded");
    }
    readScoreTable();
    return 0;
}