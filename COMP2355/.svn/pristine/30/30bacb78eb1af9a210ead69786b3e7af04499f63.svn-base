//
//  main.cpp
//  Lab7
//
//  Created by Cesar Caraveo on 1/24/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include <cstring>

void stackOverflow() {
    int arr[100000];
    stackOverflow();
}

char * reverseString(const char *input_string)
{
    char *ret = new char [strlen(input_string) + 1];
    int j = 0;
    
    for (int i = strlen(input_string) - 1; i >= 0; i--) {
        ret[j] = input_string[i];
        j++;
    }
    
    ret[j] = '\0';
    
    return ret;
}

int main(int argc, const char * argv[]) {
//    while (true) {
//        stackOverflow();
//    }
    
    char a[12] = "Hello World";
    std::cout << a << "\n";
    
    char *reverse = reverseString(a);
    std::cout << reverse << "\n";
    
    delete[] reverse;
    return 0;
}
