//
//  BitVector.cpp
//  Homework6
//
//  Created by Cesar Caraveo on 3/8/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include "BitVector.hpp"
#include <stdint.h>

BitVector::BitVector(int bitsToBeStored) : bitmapSize((bitsToBeStored + 7) / 8), bitmap(new MyArray<uint8_t>((bitsToBeStored + 7) / 8)) {
    // creates bitvector with amt of bits to be stored
}

BitVector::~BitVector() {
    // destructor, deletes memory
    delete bitmap;
    bitmap = nullptr;
}

BitVector::BitVector(const BitVector &other) {
    bitmap = new MyArray<uint8_t>(other.size());
    int len = other.size();
    
    for (int i = 0; i < len; i++) {
        bitmap->set(i, other.bitmap->get(i));
    }
}

BitVector& BitVector::operator=(const BitVector &other) {
    bitmapSize = other.getBitmapSize();
    
    for (int i = 0; i < other.size(); i++) {
        bitmap->set(i, other.bitmap->get(i));
    }
    
    return *this;
}

void BitVector::fill() {
    // fills all bits
    for (int i = 0; i < bitmapSize; i++) { // go through all uint8_ts
        bitmap->set(i, 0xFF); // set them equal to 1
    }
}

void BitVector::clear() {
    // clears all bits
    for (int i = 0; i < bitmapSize; i++) { // go through all uint8_ts
        bitmap->set(i, 0x0); // set them equal to 0
    }
}

bool BitVector::getBit(int index) {
    // gets bit at index
    int bitmapElement = getByteNumber(index); // gets element number in bitmap array where index is located
    int bitInElement = getBitNumber(index); // gets bit number in uint8_t in bitmap array where index is located
    
    uint8_t temp = bitmap->get(bitmapElement) >> (7 - bitInElement); // right-shift uint8_t element by 1 less than bit location to LSB
    uint8_t mask = uint8_t(0x1); // mask is equal to 00000001
    temp = temp & mask; // and temp with 00000001 mask to get the value of the LSB
    
    if (temp == 0) { // if bit = 0, return false
        return false;
    }
    
    return true; // return true otherwise (if bit = 1)
}

void BitVector::setBit(int index, int value) {
    // sets value to bit at index
    int bitmapElement = getByteNumber(index); // get uint8_t corresponding to index
    int bitInElement = getBitNumber(index); // get bit that represents index
    
    uint8_t temp = bitmap->get(bitmapElement);
    
    if (value == 1) { // if value is 1
        uint8_t mask = uint8_t(0x1) << (7 - bitInElement); // creates mask with all 0s except a 1 at the index of the bit that needs to change
        temp = temp | mask; // adds 1 at bit
    }
    
    else { // if value is 0
        uint8_t mask1 = uint8_t(0x1) << (7 - bitInElement); // first mask with all 0s except for a 1 at the bitIndex
        uint8_t mask2 = 0xFF; // 8-bit mask with all 1s;
        uint8_t finalMask = mask2 ^ mask1; // mask with all 1s except a 0 at bitIndex
        temp = temp & finalMask; // temp but with a 0 at bitIndex
    }
    
    bitmap->set(bitmapElement, temp);
}

void BitVector::resize(int newSize) {
    bitmap->resize(newSize);
    bitmapSize = newSize; // update size
}

int BitVector::size() const {
    // returns number of bits that can be stored
    return bitmapSize * 8;
}

int BitVector::getBitmapSize() const {
    return bitmapSize;
}

int BitVector::getByteNumber(int index) { // returns which byte (uint8_t) contains byte number index
    return index / 8; // index will be in [0,x*y*z - 1] range; divide by 8 to get element in array
}

uint8_t BitVector::getBitNumber(int index) {
    // returns which bit in the byte corresponds to byte number index
    return index % 8;
}

