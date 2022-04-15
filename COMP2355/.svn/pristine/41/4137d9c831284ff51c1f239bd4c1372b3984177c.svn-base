//
//  BitVector.h
//  Homework5
//
//  Created by Cesar Caraveo on 2/22/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef BitVector_h
#define BitVector_h

#include <stdint.h>

class BitVector {
public:
    BitVector(int bitsToBeStored); // creates bitvector with amt of bits to be stored
    ~BitVector(); // destructor, deletes memory
    BitVector(const BitVector &other);
    BitVector &operator=(const BitVector &other);
    void fill(); // fills all bits
    void clear(); // clears all bits
    bool getBit(int index); // gets bit at index
    void setBit(int index, int value); // sets value to bit at index
    void resize(int newSize); // resize
    int size() const; // returns number of bits that can be stored
    int getBitmapSize() const;
    int getByteNumber(int index); // returns which byte (uint8_t) contains byte number index
    uint8_t getBitNumber(int index); // returns which bit in the byte corresponds to byte number index

private:
    uint8_t *bitmap;
    int bitmapSize;
};

#endif /* BitVector_h */
