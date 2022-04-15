//
//  main.cpp
//  Demo
//
//  Created by Cesar Caraveo on 3/13/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
class myClass {
public:
    myClass() {
        x = &y;
    }
    
    int *x, y;
};

void fun1(int *val) {
    val[0] = 3;
}

void fun2(int &val) {
    val = 4;
}

int main(int argc, const char * argv[]) {
    myClass a;
    myClass *b = new myClass;
    
    fun1(a.x);
    fun1(&b->y);
    fun2(a.y);
    fun2(*b->x);
    
    std::cout << b->y;
    return 0;
}
