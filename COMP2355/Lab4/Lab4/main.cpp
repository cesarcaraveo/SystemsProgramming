//
//  main.cpp
//  Lab4
//
//  Created by Cesar Caraveo on 1/12/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>

// structs

struct pair {
    int a, b;
};

struct largeArray {
    int arr[10000];
    int arrayLength = 10000;
};

// fuction declarations

void swap_value(int a, int b);
void swap_reference(int &a, int &b);
void swap_pointer(int *a, int *b);
void swap_value(pair p);
void swap_reference(pair &p);
void swap_pointer(pair *p);
int add_array(largeArray a, int val);
int add_array_references(const largeArray &a, int ref);

// main

int main(int argc, const char * argv[]) {
    int a = 3;
    int b = 5;
    
    // ints
    
    std::cout << "a = " << a << ", b = " << b << "\n";
    swap_value(a, b); // swap values
    std::cout << "swapped values: a = " << a << ", b = " << b << "\n";
    swap_reference(a, b); // swap references
    std::cout << "swapped references: a = " << a << ", b = " << b << "\n";
    swap_pointer(&a, &b); // swap pointers
    std::cout << "swapped pointers: a = " << a << ", b = " << b << "\n\n";
    
    // pairs
    
    pair p = {5, 7};
    
    std::cout << "a = " << p.a << ", b = " << p.b << "\n";
    swap_value(p); /// swap values
    std::cout << "swapped pair values: a = " << p.a << ", b = " << p.b << "\n";
    swap_reference(p); // swap references
    std::cout << "swapped pair references: a = " << p.a << ", b = " << p.b << "\n";
    swap_pointer(&p); // swap pointers
    std::cout << "swapped pair pointers: a = " << p.a << ", b = " << p.b << "\n\n";
    
    // large array
    
    largeArray array;
    
    int iterations = 100000;
    
    for (int i = 0; i < array.arrayLength; i++) {
        array.arr[i] = rand() % 100; // random number generator was searched online
    }
    
    std::chrono::time_point<std::chrono::system_clock> start, end; // declare clock variables
    start = std::chrono::system_clock::now(); // start clock
    
    for (int i = 0; i < iterations; i++) { // go through array
        add_array(array, 50); // add array by values
    }
    
    end = std::chrono::system_clock::now(); // end clock
    std::chrono::duration<double> elapsed_seconds = end-start; // get total time
    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";

    start = std::chrono::system_clock::now(); // start clock again
    
    for (int i = 0; i < iterations; i++) { // go through array
        add_array_references(array, 50); // add array
    }
    
    end = std::chrono::system_clock::now(); // end clock
    elapsed_seconds = end-start; // total time
    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    
    return 0;
}

// function definititions

void swap_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_reference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_pointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_value(pair p) {
    int temp = p.a;
    p.a = p.b;
    p.b = temp;
}

void swap_reference(pair &p) {
    int temp = p.a;
    p.a = p.b;
    p.b = temp;
}

void swap_pointer(pair *p) {
    int temp = p -> a;
    p -> a = p -> b;
    p -> b = temp;
}

int add_array(largeArray a, int val) {
    int sum = 0;
    for (int i = 0; i < val; i++) {
        sum+= a.arr[i];
    }
    
    return sum;
}

int add_array_references(const largeArray &a, int ref) {
    int sum = 0;
    for (int i = 0; i < ref; i++) {
        sum+= a.arr[i];
    }
    
    return sum;
}



