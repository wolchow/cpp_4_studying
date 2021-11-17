
#include "helpers.h"

int getRandomValue(unsigned int max_value = 100) {
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	const int randomValue = std::rand() % max_value;
	return randomValue;
}

void pretty_printer (const std::string str, char decorator = '*') {
	int len = str.size(); //sizeof(str);
	len > 1 ? len - 1 : len; 
    std::cout << std::string (len, decorator) << std::endl;
	std::cout << str << std::endl;
	std::cout << std::string (len, decorator) << std::endl;
}

bool writeScore(std::string username, int attempts_count, const std::string filename = "high_scores.txt") {
    std::ofstream out_file{filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << filename << "!" << std::endl;
			return false;
		}
		// Append new results to the table:
		out_file << username << ' ';
		out_file << attempts_count;
		out_file << std::endl;
    return true;
}

bool readScoreTable(const std::string filename = "high_scores.txt") {
		std::ifstream in_file{filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << filename << "!" << std::endl;
			return false;
		}
		pretty_printer("*");
		pretty_printer("High scores table:");
		std::string username;
		int high_score = 0;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();
			if (in_file.fail()) {
				break;
			}
			// Print the information to the screen
			std::cout << username << '\t\t' << high_score << std::endl;
		}
    return true;
}

std::string getUserName(){
    std::string userName;
    std::cout << "Hello! Please, enter your name:" << std::endl;
    std::cin >> userName;
    return userName;
}


