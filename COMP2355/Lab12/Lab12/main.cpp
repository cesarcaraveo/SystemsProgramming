//
//  main.cpp
//  Lab12
//
//  Created by Cesar Caraveo on 2/16/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"
#include <string.h>

int main(int argc, const char * argv[]) {
    LinkedList<uint64_t> l;
    
    for (int i = 0; i < 10; i++) {
        l.insertAtHead(i);
    }
    
    l.print();
    
    for (int i = 0; i < 10; i++) {
        l.removeHead();
    }
    
    LinkedList<std::string> s;
    
    for (int i = 0; i < 10; i++) {
        s.insertAtHead("hello");
    }
    
    s.print();
    
    for (int i = 0; i < 10; i++) {
        s.removeHead();
    }
    
    return 0;
}
