#include "seqContainer.h"
#include "lstContainer.h"
#include <iostream>

int main () {
    seqCont<int> cont {1};
    // listContainer<int> cont {};    
     for (int i = 0; i < 10; ++i) {
         cont.pushBack(i);
     }

    cont.erase(2);
    cont.erase(3);
    cont.erase(4);
    std::cout << "After erase" << std::endl;
    std::cout << cont << std::endl;
    cont.insert(10, 0);
    cont.insert(20, 4);
    std::cout << "After insert" << std::endl;
    std::cout << cont << std::endl;
    cont.pushBack(30);
    std::cout << "After pushBack" << std::endl;
    std::cout << cont << std::endl;
    
    return 0;

}