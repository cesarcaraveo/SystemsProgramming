//
//  MyString.cpp
//  Lab11
//
//  Created by Cesar Caraveo on 2/14/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include "MyString.hpp"
#include <cstring>
#include <iostream>

// default constructor
MyString::MyString() : string(new char[1]) {
    string[0] = '\0';
}

// copy constructor
MyString::MyString(const MyString &other) {
    string = new char[std::strlen(other.string) + 1];
    size_t len = strlen(other.string);
    
    for (int i = 0; i < len; i++) { // go through array
        string[i] = other.string[i]; // value at string[i] gets value in same location in other
    }
    
    string[len] = '\0'; // null terminator
}

// copy constructor
MyString::MyString(const char *other) {
    string = new char[std::strlen(other) + 1];
    size_t len = strlen(other);
    
    for (int i = 0; i < len; i++) { // go through array
        string[i] = other[i]; // value at string[i] gets value in same location in other
    }
    
    string[len] = '\0'; // null terminator
}

// destructor
MyString::~MyString() {
    delete[] string;
    string = nullptr;
}

// assignment operator
MyString& MyString::operator=(const MyString &other) {
    size_t len = other.length();

    for (int i = 0; i < len; i++) {
        string[i] = other.string[i];
    }
    
    string[len] = '\0'; // null terminator

    return *this;
}


// returns length of string
size_t MyString::length() const {
    return strlen(string);
}

// returns pointer to string
const char* MyString::cString() const {
    return string;
}

