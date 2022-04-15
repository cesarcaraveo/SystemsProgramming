//
//  MyString.cpp
//  Lab15
//
//  Created by Cesar Caraveo on 2/28/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include "MyString.hpp"
#include <cstring>
#include <iostream>

MyString::MyString()
{
    string = new char[1];
    string[0] = '\0';
}

MyString::MyString(const MyString& s)
{
    string = new char[s.length()+1];
    for(int i=0; i < s.length(); i++)
    {
        string[i] = s.string[i];
    }
    string[s.length()] = '\0';
    
}

MyString::MyString(const char *s)
{
    string = new char[strlen(s)+1];
    
    for(int i=0; i < strlen(s); i++)
    {
        string[i] = s[i];
    }
    string[strlen(s)] = '\0';
    
}

MyString::~MyString()
{
    delete[] string;
    string = NULL;
}

MyString& MyString::operator=(const MyString& s)
{
    if(this == &s) return *this;
    
    char *tmp = new char[s.length()+1];
    for(int i=0; i < s.length(); i++)
    {
        tmp[i] = s.string[i];
    }
    tmp[s.length()] = '\0';
    
    delete[] string;
    string = tmp;
    
    return *this;
    
}

MyString &MyString::operator+=(const MyString &s) {
    size_t sLength = s.length();
    size_t thisLength = this->length();
    size_t newArrayLength = sLength + thisLength + 1;
    char *temp = new char[newArrayLength];
    
    for(int i=0; i < thisLength; i++)
    {
        temp[i] = this->string[i];
    }
    
    for (int i = 0; i < sLength; i++) {
        temp[thisLength + i] = s.string[i];
    }
    
    temp[newArrayLength - 1] = '\0';
    
    delete[] string;
    string = temp;
    
    return *this;
}

MyString operator+(const MyString &s1, const MyString &s2) {
    MyString temp(s1);
    temp+= s2;
    return temp;
}


char MyString::operator[](size_t i) const {
    size_t stringLength = this->length();
    
    if (i > stringLength) {
        return '\0';
    }

    return string[i];
}

char &MyString::operator[](size_t i) {
    size_t stringLength = this->length();
    
    if (i > stringLength) {
        return string[stringLength]; // return reference to this
    }
    
    return string[i];
}

std::ostream& operator<<(std::ostream& os, const MyString& s) {
    os << s.cString();
    
    return os;
}


size_t MyString::length() const
{
    return strlen(string);
}

const char* MyString::cString() const
{
    return string;
}
