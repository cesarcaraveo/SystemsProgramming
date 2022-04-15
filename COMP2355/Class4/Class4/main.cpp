//
//  main.cpp
//  Class4
//
//  Created by Cesar Caraveo on 1/12/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {

    // question 1
    
    int8_t t8;
    int16_t t16;
    int64_t t64;
    
    int8_t* pointer8 = &t8;
    int16_t* pointer16 = &t16;
    int64_t* pointer64 = &t64;
    int8_t& ref8 = t8;
    
    std::cout << "sizeof(pointer8): " << sizeof(pointer8) << "\nsizeof(pointer16): " << sizeof(pointer16) << "\nsizeof(pointer64): " << sizeof(pointer64) << "\n";
    
    // this shows that it allocates the max amount of memory for the variables (8 bytes)
    
    // question 2
    
    printf("%p", &t8);
    printf("\n%p", pointer8);
    printf("\n%p", &pointer8);
    printf("\n%p", ref8);

    
    // the address of the variable and the value of the pointer of that variable are the same
    // the address of the pointer is not the same
    // references are not stored in memory
    
    // question 3
    
    /*
    struct letters {
        int a, b, c, d;
    };
    
    struct myStruct {
        letters p;
        letters *p_p;
    };
    
    void MakeLetters1(letters &p)
    {
        // . . .
    }
    
    void MakeLetters2(letters *p)
    {
        // . . .
    }
    
    int main(int, const char **)
    {
        myStruct s;
        myStruct *s_p = &s;
        
        Makeletters2(&(s.p)); //
        
        Makeletters1(*(s.p_p)); // dereferencing
        
        Makeletters1(s_p->p);
        
        Makeletters2(s_p->p_p);
        
        letters p1;
        letters *p_p1;
        
        MakeLetters1(p1); // pass p1
        
        MakeLetters1(*p_p1); // pass p_p1
        
        MakeLetters2(&p1); // pass p1
        
        MakeLetters2(p_p1); // pass p_p1
    }
    
    return 0;
     */
    
    // question 4
    
    /*
    int a;
    int* b;
    int& c = a;
    
    // a = null
    // b = null
    // c = null
    
    a = 3;
    
    // a = 3
    // b = null
    // c = 3
    
    b = &a;
    
    // a = 3
    // b = 3
    // c = 3
    
    c = 7;
    
    // a = 7
    // b = 7
    // c = 7
    
    *b = 9;
    
    // a = 9
    // b = 9
    // c = 9
     
    a++; // works
    
    b++; // logical error
    
    c++; // works
    
    b = a; // error
    
    b = &a; // works
    
    b = *a; // error
    
    a = b; // error
    
    a = *b; // works
    
    a = &b; // error
    
    c = a; // works
    
    c = *a; // error
    
    c = &a; // error
     */
}
