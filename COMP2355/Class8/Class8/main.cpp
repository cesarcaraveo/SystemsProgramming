//
//  main.cpp
//  Class8
//
//  Created by Cesar Caraveo on 1/26/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

//#include <iostream>
//
//bool foo(int a, int b, int c) {
//    bool a1 = !(a & 1);
//    std::cout << a1 << "\n";
//    bool ab = a1 && !(b & 1);
//    std::cout << ab << "\n";
//    return ab && !(c & 1);
//}
//
//int main(int argc, const char * argv[]) {
//    std::cout << foo(3, 3, 3) << "\n";
//    return 0;
//}

#include <iostream>
using std::cout;
using std::endl;

int foo(int a = 1, bool b = false, double c = 3.1415);

int main() {
    cout << foo() << "\n"
    << foo(0) << "\n"
    << foo(-1) << "\n"
    << foo(-1, true) << "\n"
    << foo(-1, true, 3.14) << "\n"
    << foo(-1, false, 3.14) << "\n"
    << foo(1, false, 3.1415) << "\n"
    << endl;
    
    return 0;
}

int foo(int a, bool b, double c) {
    if (a == 0) return 1;
    if (!b) return 2;
    if (a == 1 && c == 3.14) return 3;
    return 4;
}

