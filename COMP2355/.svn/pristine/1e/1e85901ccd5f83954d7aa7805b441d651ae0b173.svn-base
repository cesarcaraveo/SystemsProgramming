//
//  main.cpp
//  Lab17
//
//  Created by Cesar Caraveo on 3/7/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>

int main(int argc, const char * argv[]) {
    std::vector<uint64_t> fib; // fibonacci numbers
    
    fib.push_back(0);
    fib.push_back(1); // first number
    fib.push_back(1); // second number in sequence
    
    std::unordered_map<uint64_t, int> fibMap; // key is fib number, value is index of that # in sequence
    
    fibMap[1] = 2; // fib number 1 is at index 2
    
    // initializing all fib numbers from 3 to and including 93
    for (int i = 3; i <= 93; i++) {
        uint64_t minusOne = fib[i-1]; // find i - 1
        uint64_t minusTwo = fib[i-2]; // find i - 2
        uint64_t value = minusOne + minusTwo; // sum of both values above (new fib number)
        fib.push_back(value); // add new fib number to vector
        fibMap[value] = i; // add fib number and index to map
    }
    
    std::cout << "Fibonnaci numbers in order:\n";
    
    // iterating through vector using iterator
    int index = 0;
    for (std::vector<uint64_t>::iterator current = fib.begin(); current != fib.end(); current++) {
        std::cout << index << " " << *current << "\n";
        index++;
    }
    
    std::cout << "Fibonacci numbers and indices, unordered:\n";
    
    // iterating through map using iterator
    for (std::unordered_map<uint64_t, int>::iterator i = fibMap.begin(); i != fibMap.end(); i++) {
        std::cout << i->second << " " << i->first << "\n";
    }
    
    std::cout << "Testing fibonacci numbers 1 to 15:\n";
    
    for (int i = 1; i <= 15; i++) {
        auto value = fibMap.find(i);
        
        if (value != fibMap.end()) {
            std::cout << i << " " << value->second << "\n";
        }
        
        else {
            std::cout << i << " " << "no\n";
        }
    }
    return 0;
}
