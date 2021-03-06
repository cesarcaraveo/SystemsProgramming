//
//  main.cpp
//  Lab5
//
//  Created by Cesar Caraveo on 1/17/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include <cstdio>

struct Student {
    int studentId;
    int assignmentGrades[4];
};

int main(int argc, const char * argv[]) {
    FILE* file = fopen("lab5.bin", "wb+");
    
    // student object initializations
    
    Student students[5];
    
    for (int i = 0; i < 5; i++) {
        students[i].studentId = i;
    }
    
    // reading grades from array
    
    int grade;
    
    std::cout << "Please enter student 1's four grades: ";
    for (int i = 0; i < 4; i++) {
        std::cin >> grade;
        students[0].assignmentGrades[i] = grade;
    }
    
    if (fwrite(&students[0], sizeof(students[0]), 1, file) != 1) {
        std::cout << "error writing s1";
        return EXIT_FAILURE;
    }
    
    
    std::cout << "Please enter student 2's four grades: ";
    for (int i = 0; i < 4; i++) {
        std::cin >> grade;
        students[1].assignmentGrades[i] = grade;
    }
    
    if (fwrite(&students[1], sizeof(students[1]), 1, file) != 1) {
        std::cout << "error writing s2";
        return EXIT_FAILURE;
    }
    
    std::cout << "Please enter student 3's four grades: ";
    for (int i = 0; i < 4; i++) {
        std::cin >> grade;
        students[2].assignmentGrades[i] = grade;
    }
    
    if (fwrite(&students[2], sizeof(students[2]), 1, file) != 1) {
        std::cout << "error writing s3";
        return EXIT_FAILURE;
    }
    
    std::cout << "Please enter student 4's four grades: ";
    for (int i = 0; i < 4; i++) {
        std::cin >> grade;
        students[3].assignmentGrades[i] = grade;
    }
    
    if (fwrite(&students[3], sizeof(students[3]), 1, file) != 1) {
        std::cout << "error writing s4";
        return EXIT_FAILURE;
    }
    
    std::cout << "Please enter student 5's four grades: ";
    for (int i = 0; i < 4; i++) {
        std::cin >> grade;
        students[4].assignmentGrades[i] = grade;
    }
    
    if (fwrite(&students[4], sizeof(students[4]), 1, file) != 1) {
        std::cout << "error writing s5";
        return EXIT_FAILURE;
    }
    
    // read file
    
    if (fseek(file, -(sizeof(Student)), SEEK_END) != 0) { // seek
        std::cout << "error reading";
        return EXIT_FAILURE;
    }
    
    int offset = 0;
    
    for (int i = 4; i >= 0; i--) {
        if (fseek(file, -(sizeof(Student) * offset), SEEK_CUR) != 0) { // seek
            std::cout << "error with seek";
            return EXIT_FAILURE;
        }
        
        std::cout << fread(&students, sizeof(Student), 1, file);
    }
    
    
    return 0;
}
