#ifndef HAPPY_H
#define HAPPY_H

template <typename T> T sumOfSquaredDigits(T number, const T radix);
template <typename T> bool isHappy(const T number, const T radix = 10);

template <typename T> T sumOfSquaredDigits(T number, const T radix) {
    T digit;
    T sum = 0;
    
    // 0 special case
    if (number == 0) {
        sum = 0;
    }
    
    while (number > 0) {
        digit = number % radix; // isolates least significant digit
        number /= radix; // divide by radix to move decimal over
        sum += digit * digit; // add digit squared to sum
    }
    
    return sum;
}

template <typename T> bool isHappy(const T number, const T radix) {
    if (number == 1) {
        return true;
    }
        
    T tortoise = sumOfSquaredDigits(number, radix);
    T hare = sumOfSquaredDigits(tortoise, radix);
    
    if (tortoise == 1 || hare == 1) {
        return true;
    }

    while (tortoise != hare) {
        tortoise = sumOfSquaredDigits(tortoise, radix);
        hare = sumOfSquaredDigits(sumOfSquaredDigits(hare, radix), radix);
        
        if (tortoise == 1 || hare == 1) {
            return true;
        }
    }
    
    return false;
}

#endif
