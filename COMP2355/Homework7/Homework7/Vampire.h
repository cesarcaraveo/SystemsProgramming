#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <string>

template <typename T> std::string integerToString(T n, const T radix = 10);
template <typename T> bool endsWithZero(const T number, const T radix);
template <typename T> bool isVampire(const T a, const T b, const T radix = 10);


template <typename T> std::string integerToString(T number, const T radix) {
    std::string string;
    T digit;
    
    // 0 special case
    if (number == 0) {
        string += std::to_string(0);
    }
    
    while (number > 0) {
        digit = number % radix; // extracts last digit
        number /= radix; // moves decimal place over
        
        if (digit < 10)
            string.push_back(static_cast<char>(digit + '0'));
        else {
            string.push_back(static_cast<char>(digit + 'A' - 10));
        }
    }
    
    string = std::string(string.crbegin(), string.crend());
    return string;
}

template <typename T> bool endsWithZero(const T number, const T radix) {
    if (number % radix == 0) {
        return true;
    }
    
    return false;
}

template <typename T> bool isVampire(const T a, const T b, const T radix) {
    // Tests whether a * b is a vampire number using a specified radix
    
    if (endsWithZero(a, radix) && endsWithZero(b, radix)) {
        return false;
    }
        
    std::string product = integerToString(a * b, radix);
    std::string fangs = integerToString(a, radix) + integerToString(b, radix);
        
    std::sort(product.begin(), product.end());
    std::sort(fangs.begin(), fangs.end());
    
    return product == fangs;
}

#endif

