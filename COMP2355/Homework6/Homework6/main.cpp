//
//  main.cpp
//  Homework6
//
//  Created by Cesar Caraveo on 3/7/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include "VoxelShape.hpp"

int main(int argc, const char * argv[]) {
    char fileName[] = "file.stl"; // filename
    VoxelShape model(100, 100, 100);
//        model.fill();
//        model.subtractSphere(49.5, 49.5, 49.5, 50);
//        model.clear();

    model.addSphere(70, 70, 57, 17);
    model.subtractSphere(70, 70, 72, 23);
    model.addSphere(30, 70, 57, 17);
    model.subtractSphere(30, 70, 72, 23);
    model.addSphere(50, 50, 50, 17);
    model.addSphere(58, 52, 65, 5);
    model.addSphere(42, 52, 65, 5);

    writeSTL(model, fileName); // create STL file
    
    return 0;
}
