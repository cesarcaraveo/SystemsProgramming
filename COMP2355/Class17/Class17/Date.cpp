//
//  Date.cpp
//  Class17
//
//  Created by Cesar Caraveo on 2/28/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include "Date.hpp"
#include <iostream>

int Date::operator-(const Date &other) const { // returns duration between two dates
    // Assumes 12 months, 30 days each
    return 360 * (year - other.year) + 30 * (month - other.month) + (day - other.day);
}

Date &Date::operator++() {  // pre-increment
    std::cout << "pre-increment";
    increment();
    return *this;
}

Date &Date::operator++(int) { // post-increment
    std::cout << "post-increment";
    increment();
    return *this;
}

void Date::increment() {
    ++day;
    if (day > 30) {
        day = 1;
        ++month;
    }
    
    if (month > 12) {
        month = 1;
        ++year;
    }
}

bool Date::operator==(const Date &other) const {
    return (day == other.day) && (month == other.month) && (year == other.year);
}

std::ostream &operator<<(std::ostream &out,const Date &d) {
    out << d.year << "-" << d.month << "-" << d.day;
    return out;
}


