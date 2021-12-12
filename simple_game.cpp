#include <iostream>
#include "helpers.h"





int main(int argc, char** argv) {

    int randNumber = 0;
    std::string *userName = nullptr;
    int score = 0;
    
    randNumber = getArgs(argc, argv);
    randNumber ? getRandomValue(randNumber) : getRandomValue();
    
    *userName = getUserName();
    score =  inputLoop(*userName, randNumber);

    if (score > 0 && writeScore(*userName, score)) {
        
        pretty_printer("Score recorded");
        
    }

    readScoreTable();
    return 0;
}