#pragma once

#include <string>

const std::string table_filename = "high_scores.txt";

int getRandomValue(unsigned int max_value  = 100);
int getArgs(int argc, char **argv);

int inputLoop(const std::string userName, const int randNumber); 

bool writeScore(std::string username, int attempts_count, const std::string = table_filename);
bool readScoreTable(const std::string filename = "high_scores.txt");

std::string getUserName();

void pretty_printer(const std::string, char decorator = '*');


