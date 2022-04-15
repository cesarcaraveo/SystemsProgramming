//
//  main.cpp
//  Class17
//
//  Created by Cesar Caraveo on 2/28/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include "Date.hpp"

int main(int argc, const char * argv[]) {
    Date d1;
    Date d2{2, 1, 1980};
    
    std::cout << "d1 - d1 = " << (d1 - d1) << "\n";
    std::cout << "d1 - d2 = " << (d1 - d2) << "\n";
    std::cout << "d2 - d1 = " << (d2 - d1) << "\n";
    
    d1++;
    ++d1;
    std::cout << "\n";
    
    if (d1 == d1) {
        std::cout << "d1 is the same as itself\n";
    }
    
    else {
        std::cout << "somehow d1 is not itself\n";
    }
    
    std::cout << d1;

    return 0;
}
