//
//  main.cpp
//  Homework2
//
//  Created by Cesar Caraveo on 1/19/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include "VoxelModel.h"
#include <iomanip>

int main(int argc, const char * argv[]) {
    uint64_t model = fullModel(); // model
    std::cout << "Model is: 0x" << std::hex << model << "\n";
    bool output = getBit(model, 1, 0, 1);
    std::cout << "Is bit true (1) or false (0)?: " << output << "\n";
    
    model = toggleBit(model, 1, 0, 1);
    output = getBit(model, 1, 0, 1);
    std::cout << "After toggling, is bit true (1) or false (0) now?: " << output << "\n";
    
    model = setBit(model, 1, 0, 1);
    output = getBit(model, 1, 0, 1);
    std::cout << "After setting, is bit true (1) or false (0) now?: " << output << "\n";
    
    model = clearBit(model, 1, 0, 1);
    output = getBit(model, 1, 0, 1);
    std::cout << "After clearing, is bit true (1) or false (0) now?: " << output << "\n";
    std::cout << "Model is: 0x" << std::hex << model << "\n";
    
    return 0;
}

