//
//  MyString.hpp
//  Lab15
//
//  Created by Cesar Caraveo on 2/28/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <cstdlib>
#include <iostream>

class MyString {
public:
    MyString();
    MyString(const MyString &s);
    MyString(const char *s);
    ~MyString();
    MyString &operator=(const MyString &s);
    MyString &operator+=(const MyString &s);
    char operator[](size_t i) const;
    char &operator[](size_t i);
    size_t length() const;
    const char *cString() const;
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
private:
    char *string;
    size_t stringLength;  // not required, but handy to keep around
    // You may add helper functions here if desired
};

MyString operator+(const MyString &s1, const MyString &s2);

#endif /* MyString_hpp */
