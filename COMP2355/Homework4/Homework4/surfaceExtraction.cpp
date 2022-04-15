//
//  surfaceExtraction.cpp
//  Homework3
//
//  Created by Ben Jones on 1/6/17.
//  Copyright © 2017 Ben Jones. All rights reserved.
//

#include <iostream>
#include "surfaceExtraction.hpp"
#include "VoxelModel.h"


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

void writeSTL(VoxelModel model, const char* filename) {
    FILE *f = fopen(filename, "wb+"); // create STL file
    
    char header[80]; // header
    for (int i = 0; i < 80; i++) {
        header[i] = '0'; // initialize header to all 0s
    }
    
    fwrite(header, sizeof(char), 80, f); // add header to file
    
    uint32_t numTriangles = 0;
    fwrite(&numTriangles, sizeof(uint32_t), 1, f); // add #triangles to file (size is 4 since it is 32 bits)
    
    // go through all x,y,z voxels
    
    Triangle t1, t2;
    
    for (int x = 0; x < model.x; x++) {
        for (int y = 0; y < model.y; y++) {
            for (int z = 0; z < model.z; z++) {
                if (getBit(model, x, y, z)) { // if voxel at x, y, z is on
                    if (x - 1 < 0 || !getBit(model, x - 1, y, z)) { // if off or outside of range NX
                        extractFace(x, y, z, NX, t1, t2);
                        writeTriangle(f, t1);
                        writeTriangle(f, t2);
                        numTriangles += 2; // add 2 triangles
                    }
                    
                    if (x + 1 > (model.x - 1) || !getBit(model, x + 1, y, z)) { // if off or outside of range PX
                        extractFace(x, y, z, PX, t1, t2);
                        writeTriangle(f, t1);
                        writeTriangle(f, t2);
                        numTriangles += 2; // add 2 triangles
                    }
                    
                    if (y - 1 < 0 || !getBit(model, x, y - 1, z)) { // if off or outside of range NY
                        extractFace(x, y, z, NY, t1, t2);
                        writeTriangle(f, t1);
                        writeTriangle(f, t2);
                        numTriangles += 2; // add 2 triangles
                    }
                    
                    if (y + 1 > (model.y - 1) || !getBit(model, x, y + 1, z)) { // if off or outside of range PY
                        extractFace(x, y, z, PY, t1, t2);
                        writeTriangle(f, t1);
                        writeTriangle(f, t2);
                        numTriangles += 2; // add 2 triangles
                    }
                    
                    if (z - 1 < 0 || !getBit(model, x, y, z - 1)) { // if off or outside of range NZ
                        extractFace(x, y, z, NZ, t1, t2);
                        writeTriangle(f, t1);
                        writeTriangle(f, t2);
                        numTriangles += 2; // add 2 triangles
                    }
                    
                    if (z + 1 > (model.z - 1) || !getBit(model, x, y, z + 1)) { // if off or outside of range PZ
                        extractFace(x, y, z, PZ, t1, t2);
                        writeTriangle(f, t1);
                        writeTriangle(f, t2);
                        numTriangles += 2; // add 2 triangles
                    }
                }
            }
        }
    }
    
    // go back and edit file
    
    fseek(f, 80, SEEK_SET);
    fwrite(&numTriangles, sizeof(uint32_t), 1, f);
    fclose(f);
}





