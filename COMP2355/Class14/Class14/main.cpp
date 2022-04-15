//
//  main.cpp
//  Class14
//
//  Created by Cesar Caraveo on 2/16/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include "Pair.hpp"

template <typename T>
class Foo {
public:
    Foo(T x) : x(x) {}
    void function1();

private:
    T x;
};

template <typename K>
void Foo<K>::function1() {
    
}

int main(int argc, const char * argv[]) {
//    Foo<int> bar{1}; // can omit "int"
    Pair<int, int> x{1, 2};
    x.PrintPair();
    x.setkey(3);
    x.setvalue(4);
    x.PrintPair();
    
    Pair<double, int> y{1.0, 2};
    y.PrintPair();
    y.setkey(3);
    y.setvalue(4);
    y.PrintPair();
    
    return 0;
}
