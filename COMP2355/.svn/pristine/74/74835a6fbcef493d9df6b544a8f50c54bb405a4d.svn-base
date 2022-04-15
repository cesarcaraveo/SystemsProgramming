//
//  VoxelShape.cpp
//  Homework6
//
//  Created by Cesar Caraveo on 3/8/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include "VoxelShape.hpp"
#include <math.h>

enum FaceType {
    NX,
    NY,
    NZ,
    PX,
    PY,
    PZ
};

struct Triangle{
    float normal[3];
    float v1[3];
    float v2[3];
    float v3[3];
};

VoxelShape::VoxelShape(int x, int y, int z) : x(x), y(y), z(z), vector(new BitVector(x * y * z)) {
    // creates bitvector of size xyz
}

VoxelShape::~VoxelShape() {
    // destructor -- deletes all memory
    delete vector;
    vector = nullptr;
    x = 0;
    y = 0;
    z = 0;
}

void VoxelShape::fill() {
    // fills all voxels
    vector->fill();
}

void VoxelShape::clear() {
    // clears all voxel
    vector->clear();
}

bool VoxelShape::getBit(int x, int y, int z) const { // don't have model as parameter
    // returns bit at xyz
    int index = getIndex(x, y, z);
    return vector->getBit(index);
}

void VoxelShape::setBit(int x, int y, int z) {
    // sets bit at xyz to 1
    int index = getIndex(x, y, z);
    vector->setBit(index, 1);
}

void VoxelShape::clearBit(int x, int y, int z) {
    // clears bit at xyz
    int index = getIndex(x, y, z);
    vector->setBit(index, 0);
}

void VoxelShape::toggleBit(int x, int y, int z) {
    // toggles bit at xyz
    int index = getIndex(x, y, z);
    
    // if bit is 1
    if (vector->getBit(index) == 1) {
        vector->setBit(index, 0);
    }
    
    // if bit is 0
    else {
        vector->setBit(index, 0);
    }
}

void VoxelShape::addSphere(float cx, float cy, float cz, float radius) {
    // adds sphere
    for (int x1 = 0; x1 < x; x1++) { // go through all possible x coors in sphere
        for (int y1 = 0; y1 < y; y1++) { // go through all possible y coors in sphere
            for (int z1 = 0; z1 < z; z1++) { // go through all possible z coors in sphere
                if (pow((x1 - cx), 2) + pow((y1 - cy), 2) + pow((z1 - cz), 2) < pow(radius, 2)) { // if voxel is in sphere
                    setBit(x1, y1, z1); // turn voxel on
                }
            }
        }
    }
}

void VoxelShape::subtractSphere(float cx, float cy, float cz, float radius) {
    // subtracts sphere
    for (int x1 = 0; x1 < x; x1++) { // go through all possible x coors in sphere
        for (int y1 = 0; y1 < y; y1++) { // go through all possible y coors in sphere
            for (int z1 = 0; z1 < z; z1++) { // go through all possible z coors in sphere
                if (pow((x1 - cx), 2) + pow((y1 - cy), 2) + pow((z1 - cz), 2) < pow(radius, 2)) { // if voxel is in sphere
                    clearBit(x1, y1, z1); // turn voxel on
                }
            }
        }
    }
}

void VoxelShape::toggleSphere(float cx, float cy, float cz, float radius) {
    // toggles sphere
    for (int x1 = 0; x1 < x; x1++) { // go through all possible x coors in sphere
        for (int y1 = 0; y1 < y; y1++) { // go through all possible y coors in sphere
            for (int z1 = 0; z1 < z; z1++) { // go through all possible z coors in sphere
                if (pow((x1 - cx), 2) + pow((y1 - cy), 2) + pow((z1 - cz), 2) < pow(radius, 2)) { // if voxel is in sphere
                    toggleBit(x1, y1, z1); // turn voxel on
                }
            }
        }
    }
}

int VoxelShape::getIndex(int x1, int y1, int z1) const {
    // returns index of xyz
    int index = 0;
    index = (x1 * y + y1) * z + z1; // index
    return index;
}

int VoxelShape::getX() const {
    return x;
}

int VoxelShape::getY() const {
    return y;
}

int VoxelShape::getZ() const {
    return z;
}


inline void fillPlane(int a1, int a2, int b1, int b2, int c, int cInd, Triangle& t1, Triangle& t2){
    t1.v1[cInd] = c;
    t2.v1[cInd] = c;
    t1.v2[cInd] = c;
    t2.v2[cInd] = c;
    t1.v3[cInd] = c;
    t2.v3[cInd] = c;
    int aInd = (cInd +1) % 3;
    int bInd = (cInd +2) % 3;
    
    t1.v1[aInd] = a1;
    t1.v2[aInd] = a2;
    t1.v3[aInd] = a2;
    
    t2.v1[aInd] = a1;
    t2.v2[aInd] = a2;
    t2.v3[aInd] = a1;
    
    t1.v1[bInd] = b1;
    t1.v2[bInd] = b1;
    t1.v3[bInd] = b2;
    
    t2.v1[bInd] = b1;
    t2.v2[bInd] = b2;
    t2.v3[bInd] = b2;
    
}

void extractFace(int x, int y, int z, FaceType face, Triangle& t1, Triangle& t2){
    for(int i= 0; i < 3; i++){
        t1.normal[i] = 0;
        t2.normal[i] = 0;
    }
    switch(face){
        case NX:
            t1.normal[0] = -1;
            t2.normal[0] = -1;
            fillPlane(y + 1, y, z, z+1, x, 0, t1, t2);
            break;
        case NY:
            t1.normal[1] = -1;
            t2.normal[1] = -1;
            fillPlane(z + 1, z, x, x+1, y, 1, t1, t2);
            break;
        case NZ:
            t1.normal[2] = -1;
            t2.normal[2] = -1;
            fillPlane(x + 1, x, y, y + 1, z, 2, t1, t2);
            break;
        case PX:
            t1.normal[0] = 1;
            t2.normal[0] = 1;
            fillPlane(y, y + 1, z, z +1, x + 1, 0, t1, t2);
            break;
        case PY:
            t1.normal[1] = 1;
            t2.normal[1] = 1;
            fillPlane(z, z + 1, x, x + 1, y + 1, 1, t1, t2);
            break;
        case PZ:
            t1.normal[2] = 1;
            t2.normal[2] = 1;
            fillPlane(x, x +1, y, y + 1, z + 1, 2, t1, t2);
            break;
    }
}

void writeTriangle(FILE *filename, Triangle &t) {
    uint16_t split = 0;
    fwrite(t.normal, sizeof(float), 3, filename);
    fwrite(t.v1, sizeof(float), 3, filename);
    fwrite(t.v2, sizeof(float), 3, filename);
    fwrite(t.v3, sizeof(float), 3, filename);
    fwrite(&split, sizeof(uint16_t), 1, filename);
    
}

void writeSTL(const VoxelShape &model, const char* filename) {
    MyArray<Triangle> triangles;
    
    // go through all x,y,z voxels
    
    Triangle t1, t2;
    
    for (int x = 0; x < model.getX(); x++) {
        for (int y = 0; y < model.getY(); y++) {
            for (int z = 0; z < model.getZ(); z++) {
                if (model.getBit(x, y, z)) { // if voxel at x, y, z is on
                    if (x - 1 < 0 || !model.getBit(x - 1, y, z)) { // if off or outside of range NX
                        extractFace(x, y, z, NX, t1, t2);
                        // add triangle to myarray<triangle> here
                        triangles.pushBack(t1);
                        triangles.pushBack(t2);
                    }
                    
                    if (x + 1 > (model.getX() - 1) || !model.getBit(x + 1, y, z)) { // if off or outside of range PX
                        extractFace(x, y, z, PX, t1, t2);
                        triangles.pushBack(t1);
                        triangles.pushBack(t2);
                    }
                    
                    if (y - 1 < 0 || !model.getBit(x, y - 1, z)) { // if off or outside of range NY
                        extractFace(x, y, z, NY, t1, t2);
                        triangles.pushBack(t1);
                        triangles.pushBack(t2);
                    }
                    
                    if (y + 1 > (model.getY() - 1) || !model.getBit(x, y + 1, z)) { // if off or outside of range PY
                        extractFace(x, y, z, PY, t1, t2);
                        triangles.pushBack(t1);
                        triangles.pushBack(t2);
                    }
                    
                    if (z - 1 < 0 || !model.getBit(x, y, z - 1)) { // if off or outside of range NZ
                        extractFace(x, y, z, NZ, t1, t2);
                        triangles.pushBack(t1);
                        triangles.pushBack(t2);
                    }
                    
                    if (z + 1 > (model.getZ() - 1) || !model.getBit(x, y, z + 1)) { // if off or outside of range PZ
                        extractFace(x, y, z, PZ, t1, t2);
                        triangles.pushBack(t1);
                        triangles.pushBack(t2);
                    }
                }
            }
        }
    }
    
    // create file and loop through array to add triangles to file
    
    FILE *f = fopen(filename, "wb+"); // create STL file
    
    char header[80]; // header
    for (int i = 0; i < 80; i++) {
        header[i] = '0'; // initialize header to all 0s
    }
    
    fwrite(header, sizeof(char), 80, f); // add header to file
    
    uint32_t numTriangles = triangles.size();
    fwrite(&numTriangles, sizeof(uint32_t), 1, f); // add #triangles to file (size is 4 since it is 32 bits)
    
    for (int i = 0; i < numTriangles; i++) {
        writeTriangle(f, triangles.get(i));
    }
    
    fclose(f);
}


