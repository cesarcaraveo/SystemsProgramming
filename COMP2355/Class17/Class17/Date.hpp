//
//  Date.hpp
//  Class17
//
//  Created by Cesar Caraveo on 2/28/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include <iostream>

class Date
{
public:
    Date():day(1), month(1), year(1980){}
    Date(int d, int m, int y):day(d), month(m), year(y){}
    
    int operator-(const Date &other) const;
    
    Date &operator++(); // pre-increment
    Date &operator++(int); // post-increment
    
    bool operator==(const Date &other) const;
    
    friend std::ostream &operator<<(std::ostream &out, const Date &);
private:
    void increment();
    int day;
    int month;
    int year;
};

#include <stdio.h>

#endif /* Date_hpp */
