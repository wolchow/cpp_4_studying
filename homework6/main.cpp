#include "seqContainer.h"
#include <iostream>

int main () {
    seqCont<int> cont {};    
    for (int i = 0; i < 10; ++i) {
        cont.pushBack(i); 
        // std::cout << "Value " << i << "added" << std::endl;
    }

     std::cout << cont << std::endl;
     std::cout << "Container size: " << cont.size() << std::endl;
    //  if (argc > 2) {cont.insert(atoi(argv[1]), atoi(argv[2]));}
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
    delete &cont;
    return 0;

}