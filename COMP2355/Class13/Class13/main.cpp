//
//  main.cpp
//  Class13
//
//  Created by Cesar Caraveo on 2/14/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>

class Test {
public:
    Test() : x(1), y(new int(2)) { // intializer list
        // default constructor
    }
    
    Test(const Test &other) : x(other.x), y(new int(*other.y)) {
        // copy constructor
    }
    
    ~Test() {
        // descructor
        delete y;
        y = nullptr;
    }
    
    Test& operator=(const Test &other) {
        // assignment operator
        x = other.x;
        *y = *other.y;
        return *this;
    }
private:
    int x;
    int *y;
};

int main(int argc, const char * argv[]) {
    {
        Test foo; // default constructor
        Test bar = foo; // copy constructor
        bar = foo; // assignment operator
    }
    return 0;
}
