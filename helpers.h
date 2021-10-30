#pragma once

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

int getRandomValue(unsigned int max_value);

bool writeScore(std::string username, int attempts_count, const std::string filename);
bool readScoreTable(const std::string filename);

std::string getUserName();

void pretty_printer(const std::string, char decorator);


