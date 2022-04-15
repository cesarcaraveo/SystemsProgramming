//
//  main.cpp
//  Homework4
//
//  Created by Cesar Caraveo on 2/7/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include "surfaceExtraction.hpp"
#include "VoxelModel.h"

int main(int argc, const char * argv[]) {
    char fileName[] = "file.stl"; // filename
    VoxelModel model = allocateModel(100, 100, 100);
//    fillModel(model);
//    subtractSphere(model, 49.5, 49.5, 49.5, 50);

    addSphere(model, 70, 70, 57, 17);
    subtractSphere(model, 70, 70, 72, 23);
    addSphere(model, 30, 70, 57, 17);
    subtractSphere(model, 30, 70, 72, 23);
    addSphere(model, 50, 50, 50, 17);
    addSphere(model, 58, 52, 65, 5);
    addSphere(model, 42, 52, 65, 5);
    
    writeSTL(model, fileName); // create STL file
    deleteModel(model);
    return 0;
}
