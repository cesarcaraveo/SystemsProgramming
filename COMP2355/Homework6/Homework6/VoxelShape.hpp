//
//  VoxelShape.hpp
//  Homework6
//
//  Created by Cesar Caraveo on 3/8/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef VoxelShape_hpp
#define VoxelShape_hpp

#include <stdio.h>
#include "BitVector.hpp"

class VoxelShape {
public:
    VoxelShape(int x, int y, int z); // creates bitvector of size xyz
    ~VoxelShape(); // destructor -- deletes all memory
    VoxelShape(const VoxelShape &) = delete;
    VoxelShape &operator=(const VoxelShape &) = delete;
    void fill(); // fills all voxels
    void clear(); // clears all voxels
    bool getBit(int x, int y, int z) const; // returns bit at xyz
    void setBit(int x, int y, int z); // sets bit at xyz to 1
    void clearBit(int x, int y, int z); // clears bit at xyz
    void toggleBit(int x, int y, int z); // toggles bit at xyz
    void addSphere(float cx, float cy, float cz, float radius); // adds sphere
    void subtractSphere(float cx, float cy, float cz, float radius); // subtracts sphere
    void toggleSphere(float cx, float cy, float cz, float radius); // toggles sphere
    int getX() const;
    int getY() const;
    int getZ() const;
    
private:
    int x, y, z; // dimensions
    int getIndex(int x, int y, int z) const; // returns index of xyz
    BitVector *vector;
};

void writeSTL(const VoxelShape &model, const char* filename);

#endif /* VoxelShape_hpp */

