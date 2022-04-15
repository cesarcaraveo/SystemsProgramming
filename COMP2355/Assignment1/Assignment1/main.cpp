//
//  main.cpp
//  Assignment1
//
//  Created by Cesar Caraveo on 1/10/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>

int main() {
    int numbers[10]; // creates array with arrayLength elements
    int arrayLength = 10; // keeps track of array length
    
    std::cout << "Please input " << arrayLength << " numbers\n";
    
    // populate array from user
    
    for (int i = 0; i < arrayLength; i++) {
        int num; // declares num variable (acts as scanner)
        std::cin >> num; // reads in next int
        numbers[i] = num; // adds num to array
    }
    
    // print array before sort
    
    std::cout << "Numbers before sort: ";
    
    for (int i = 0; i < arrayLength; i++) { // goes through array
        std::cout << " " << numbers[i]; // prints each element
    }
    
    std::cout << "\n";
    
    // sort array
    
    for (int i = 1; i < arrayLength; i++) {
        int temp = numbers[i]; // temp variable
        int j = i - 1;
        
        while (j >= 0 && numbers[j] > temp) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        
        numbers[j + 1] = temp;
    }
    
    // print array after sort
    
    std::cout << "Numbers after sort:";
    
    for (int i = 0; i < arrayLength; i++) {
        std::cout << " " << numbers[i];
    }
    
    std::cout << "\n";
    
    return 0;
}
