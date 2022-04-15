#include <stdint.h>
#include "VoxelModel.h"
#include <iostream>
#include <math.h> // googled how to use power function

// function implementations

int getIndex(const VoxelModel &model, int x, int y, int z) {
    int index = 0; // index to be modified and returned
    
//    if (x < 0 || x >= model.x) { // checks if x is out of range
//        std::cout << "x must be in range [0, model.x - 1]\n";
//    }
//
//    if (y < 0 || y >= model.y) { // checks if y is out of range
//        std::cout << "y must be in range [0, model.y - 1]\n";
//    }
//
//    if (z < 0 || z >= model.z) { // checks if z is out of range
//        std::cout << "z must be in range [0, model.z - 1]\n";
//    }
    
    index = (x * model.y + y) * model.z + z; // index
    
    return index;
}

void getXYZ(const VoxelModel &model, int index, int &x, int &y, int &z) { // replace getX, getY, getZ
    int updateX, updateY, updateZ = 0; // new values
    int totalBits = model.x * model.y * model.z; // total bits in bitmap
    
    // get x
    updateX = index / (totalBits / model.x); // (totalbits / model.x) = amt of Xs in bitmap; index / amtX = which X
    x = updateX; // update x
    
    // get y
    int yStep = (index - (updateX * model.y * model.z));
    updateY = yStep / model.z;
    y = updateY; // update y
    
    // get z
    updateZ = yStep - (updateY * model.z);
    z = updateZ; // update z
    
    /* used getIndex equation to derive y and z*/
}

bool getBit(const VoxelModel &model, int x, int y, int z) {
    int bitIndex = getIndex(model, x, y, z); // get bit index for x,y,z
    int bitmapElement = getByteNumber(bitIndex); // gets element number in bitmap array where index is located
    int bitInElement = getBitNumber(bitIndex); // gets bit number in uint8_t in bitmap array where index is located
    
    uint8_t temp = model.bitmap[bitmapElement] >> (7 - bitInElement); // right-shift uint8_t element by 1 less than bit location to LSB
    uint8_t mask = uint8_t(0x1); // mask is equal to 00000001
    temp = temp & mask; // and temp with 00000001 mask to get the value of the LSB
    
    if (temp == 0) { // if bit = 0, return false
        return false;
    }
   
    return true; // return true otherwise (if bit = 1)
}

void setBit(VoxelModel &model, int x, int y, int z) { // returns model that's same as paramenter, except x,y,z bit is set to 1
    int bitIndex = getIndex(model, x, y, z); // get bit index for x,y,z
    int bitmapElement = getByteNumber(bitIndex); // get uint8_t corresponding to index
    int bitInElement = getBitNumber(bitIndex); // get bit that represents index
    
    uint8_t temp = model.bitmap[bitmapElement];
    uint8_t mask = uint8_t(0x1) << (7 - bitInElement); // creates mask with all 0s except a 1 at the index of the bit that needs to change
    
    temp = temp | mask; // adds 1 at bit
    model.bitmap[bitmapElement] = temp;
}

void clearBit(VoxelModel &model, int x, int y, int z) { // returns model that's same as paramenter, except x,y,z bit is set to 0
    int bitIndex = getIndex(model,x, y, z); // get bit index for x,y,z
    int bitmapElement = getByteNumber(bitIndex);
    int bitinElement = getBitNumber(bitIndex);
    
    uint8_t temp = model.bitmap[bitmapElement]; // get uint8_t where index is located
    uint8_t mask1 = uint8_t(0x1) << (7 - bitinElement); // first mask with all 0s except for a 1 at the bitIndex
    uint8_t mask2 = 0xFF; // 8-bit mask with all 1s;
    uint8_t finalMask = mask2 ^ mask1; // mask with all 1s except a 0 at bitIndex
    
    temp = temp & finalMask; // temp but with a 0 at bitIndex
    model.bitmap[bitmapElement] = temp;
}

void toggleBit(VoxelModel &model, int x, int y, int z) { // model same as paramenter but x,y,z bit is flipped
    if (getBit(model, x, y, z)) { // if getBit is true (bit at x, y, z is a 1)
        clearBit(model, x, y, z);
    }
    
    else { // if getBit is false (bit at x, y, z is a 0)
        setBit(model, x, y, z);
    }
}

VoxelModel allocateModel(int nx, int ny, int nz) {
    // create voxelmodel struct and initialize it to appropriate size and empty
    VoxelModel model = {nx, ny, nz}; // creates model with dimensions
    clearModel(model);
    
    return model; // returns model
}

void clearModel(VoxelModel &model) { // set all voxels to off (0)
        for (int i = 0; i < model.bitmapSize; i++) { // go through all uint8_ts
        model.bitmap[i] = 0x0; // set them equal to 0
    }
}

void fillModel(VoxelModel &model) { // set all voxels to on (1)
    for (int i = 0; i < model.bitmapSize; i++) { // go through all uint8_ts
        model.bitmap[i] = 0xFF; // set them equal to 1
    }
}

void deleteModel(VoxelModel &model) { // deallocate all heap memory, set model size to 0, data to null
    delete[] model.bitmap; // delete bitmap array
    model.bitmap = nullptr; // set pointer to null
    model.x = 0; // set x to null
    model.y = 0; // set y to null
    model.z = 0; // set z to null
    model.bitmapSize = 0; // set size to 0
}

int getByteNumber(int index) { // returns which byte (uint8_t) contains byte number index
    return index / 8; // index will be in [0,x*y*z - 1] range; divide by 8 to get element in array
}

uint8_t getBitNumber(int index) { // returns which bit in the byte corresponds to byte number index
    return index % 8;
}

void addSphere(VoxelModel &model, float cx, float cy, float cz, float radius) {
    for (int x = 0; x < model.x; x++) { // go through all possible x coors in sphere
        for (int y = 0; y < model.y; y++) { // go through all possible y coors in sphere
            for (int z = 0; z < model.z; z++) { // go through all possible z coors in sphere
                if (pow((x - cx), 2) + pow((y - cy), 2) + pow((z - cz), 2) < pow(radius, 2)) { // if voxel is in sphere
                    setBit(model, x, y, z); // turn voxel on
                }
            }
        }
    }
}

void subtractSphere(VoxelModel &model, float cx, float cy, float cz, float radius) {
    for (int x = 0; x < model.x; x++) { // go through all possible x coors in sphere
        for (int y = 0; y < model.y; y++) { // go through all possible y coors in sphere
            for (int z = 0; z < model.z; z++) { // go through all possible z coors in sphere
                if (pow((x - cx), 2) + pow((y - cy), 2) + pow((z - cz), 2) < pow(radius, 2)) { // if voxel is in sphere
                    clearBit(model, x, y, z); // turn voxel off
                }
            }
        }
    }
}

void toggleSphere(VoxelModel &model, float cx, float cy, float cz, float radius) {
    for (int x = 0; x < model.x; x++) { // go through all possible x coors in sphere
        for (int y = 0; y < model.y; y++) { // go through all possible y coors in sphere
            for (int z = 0; z < model.z; z++) { // go through all possible z coors in sphere
                if (pow((x - cx), 2) + pow((y - cy), 2) + pow((z - cz), 2) < pow(radius, 2)) { // if voxel is in sphere
                    toggleBit(model, x, y, z); // turn voxel on
                }
            }
        }
    }
}


