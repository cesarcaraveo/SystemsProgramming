//
//  main.cpp
//  Class5
//
//  Created by Cesar Caraveo on 1/17/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include <cstdio>

struct struct1 {
    char a, b, c;
};

struct struct2 {
    int a, b;
};

struct struct3 {
    double a, b, c;
};

struct struct4 {
    int array[3];
};

struct struct5 {
    float a, b, c;
};

int main(int argc, const char * argv[]) {
    struct1 s1;
    struct2 s2;
    struct3 s3;
    struct4 s4;
    struct5 s5;
    
    std::cout << "struct 1 = " << sizeof(s1) << "\nstruct 2 = " << sizeof(s2) <<
            "\nstruct 3 = " << sizeof(s3) << "\nstruct 4 = " << sizeof(s4) << "\nstruct 5 = "
            << sizeof(s5) << "\n";
    
    s3 = {2, 3, 4};
    
    FILE* file = fopen("hello.bin", "w");
    fwrite(&s3, sizeof(s3), 1, file);
    
    return 0;
}
