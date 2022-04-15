//
//  ReadAndWrite.h
//  Lab8
//
//  Created by Cesar Caraveo on 1/26/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef ReadAndWrite_h
#define ReadAndWrite_h
#include <iomanip>
#include <string>

template <typename T>
void ReadAndPrint(std::string str) {
    T input;
    std::cout << "Please input an " << str << ": ";
    std::cin >> input;
    std::cout << "in hex: 0x" << std::hex << input << "\nin dec: " << std::dec << input << "\n";
}

#endif /* ReadAndWrite_h */
