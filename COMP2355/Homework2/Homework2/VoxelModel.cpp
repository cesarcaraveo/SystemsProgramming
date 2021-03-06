#include <stdint.h>
#include "VoxelModel.h"
#include <iostream>
// function implementations

uint8_t getIndex(int x, int y, int z) {
    int startBit = 0; // bit will eventually represent index of bit to return
    
    if (x == 0) {
        startBit = 0; // min bit possible
    }
    
    else if (x == 1) {
        startBit = 16; // min bit possible
    }
    
    else if (x == 2) {
        startBit = 32; // min bit possible
    }
    
    else if (x == 3) {
        startBit = 48; // min bit possible
    }
    
    // if x is not between [0,3]
    
    else {
        std::cout << "x must be an integer [0-3]\n";
    }
    
    if (y == 0) {
        // do nothing
    }
    
    else if (y == 1) {
        startBit+=4; // advance index by 4
    }
    
    else if (y == 2) {
        startBit+=8; // advance index by 8
    }
    
    else if (y == 3){
        startBit+=12; // advance index by 12
    }
    
    // if y is not between [0,3]
    
    else {
        std::cout << "y must be an integer [0-3]\n";
    }
    
    if (z == 0) {
        // do nothing
    }
    
    else if (z == 1) {
        startBit++; // advance index by 1
    }
    
    else if (z == 2) {
        startBit+=2; // advance index by 2
    }
    
    else if (z == 3) {
        startBit+=3; // advance index by 3
    }
    
    // if z is not between [0-3]
    
    else {
        std::cout << "z must be an integer [0-3]\n";
    }
    
    return startBit; // returns index [0,63]
    
}

uint8_t getX(uint8_t index) {
    return index / 16; // gets x
}
uint8_t getY(uint8_t index) {
    int temp = index - (16 * getX(index)); // gets range of 16 bits
    return temp / 4; // gets y
}
uint8_t getZ(uint8_t index) {
    int temp = index - (16 * getX(index)); // gets range of 16 bits
    int y = temp / 4; // gets range of 4 bits
    return temp - (4 * y); // gets z
}

uint64_t emptyModel() {
    return 0x0; // return model with all bits set to 0
}

uint64_t fullModel() {
    return 0xFFFFFFFFFFFFFFFF; // return model with all bits set to 1
}

bool getBit(uint64_t model, int x, int y, int z) {
    int bitIndex = getIndex(x, y, z); // get bit index for x,y,z
    uint64_t temp = model >> bitIndex; // right-shift 64bit model by index to get bit to LSB
    uint64_t mask = uint64_t(0x1); // mask is equal to 00..001
    temp = temp & mask; // and temp with 00..001 mask to get the value of the LSB
    
    if (temp == 0) { // if bit = 0, return false
        return false;
    }
   
    return true; // return true otherwise (if bit = 1)
}

uint64_t setBit(uint64_t model, int x, int y, int z) { // returns model that's same as paramenter, except x,y,z bit is set to 1
    int bitIndex = getIndex(x, y, z); // get bit index for x,y,z
    uint64_t mask = uint64_t(0x1) << bitIndex; // creates mask with all 0s except a 1 at the index of the bit that needs to change
    
    return model | mask; // adds 1 at bitIndex
}

uint64_t clearBit(uint64_t model, int x, int y, int z) { // returns model that's same as paramenter, except x,y,z bit is set to 0
    int bitIndex = getIndex(x, y, z); // get bit index for x,y,z
    uint64_t mask1 = uint64_t(0x1) << bitIndex; // first mask with all 0s except for a 1 at the bitIndex
    uint64_t mask2 = fullModel(); // 64-bit mask with all 1s;
    uint64_t finalMask = mask2 ^ mask1; // mask with all 1s except a 0 at bitIndex
    
    return model & finalMask; // returns model but with a 0 at bitIndex
}

uint64_t toggleBit(uint64_t model, int x, int y, int z) { // returns model same as paramenter but x,y,z bit is flipped
    uint64_t toggled = 0; // set return variable to 0
    
    if (getBit(model, x, y, z)) { // if getBit is true (bit at x, y, z is a 1
        toggled = clearBit(model, x, y, z);
    }
    
    else { // if getBit is false (bit at x, y, z is a 0
        toggled = setBit(model, x, y, z);
    }
    
    return toggled; // returned model with bit at bitIndex flipped
}
