//
//  main.cpp
//  Homework3
//
//  Created by Cesar Caraveo on 1/26/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include "surfaceExtraction.hpp"
#include "VoxelModel.h"

int main(int argc, const char * argv[]) {
    char fileName[] = "file.stl"; // filename
    uint64_t model = emptyModel(); // creates model
    model = setBit(model, 0, 1, 0);
    model = setBit(model, 1, 0, 0);
    model = setBit(model, 1, 1, 0);
    model = setBit(model, 2, 1, 0);
    model = setBit(model, 1, 2, 0);
    model = setBit(model, 1, 1, 1);

    writeSTL(model, fileName); // create STL file
    
    return 0; // Be nice
}
