//
//  main.cpp
//  Lab9
//
//  Created by Cesar Caraveo on 2/7/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <ctime>

int main(int argc, const char * argv[]) {
    int trials = 100000;

    // 2d array
    
    int rows = 100;
    int columns = 100;
    int *twoDarray = new int[rows * columns];
    
    {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        
        // optimized for cache
        for (int t = 0; t < trials; t++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    twoDarray[rows * i + columns] += 1;
                }
            }
        }
        
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    
    {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        
        // not optimized for cache
        for (int t = 0; t < trials; t++) {
            for (int j = 0; j < columns; j++) {
                for (int i = 0; i < rows; i++) {
                    twoDarray[rows * i + columns] += 1;
                }
            }
        }
        
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    
    delete[] twoDarray;
    
    // 3d array
    
    int x = 100;
    int y = 100;
    int z = 100;
    int trial = 100;
    int *threeDarray = new int[x * y * z];
    
    {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        
        // optimized for cache
        for (int t = 0; t < trial; t++) {
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    for (int k = 0; k < z; k++) {
                        threeDarray[(i * y + j) * z + k] += 1;
                    }
                }
            }
        }
        
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    
    {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        
        // not optimized for cache
        for (int t = 0; t < trial; t++) {
            for (int k = 0; k < z; k++) {
                for (int j = 0; j < y; j++) {
                    for (int i = 0; i < x; i++) {
                        threeDarray[(i * y + j) * z + k] += 1;
                    }
                }
            }
        }
        
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    
    {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        
        // not optimized for cache
        for (int t = 0; t < trial; t++) {
            for (int k = 0; k < z; k++) {
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        threeDarray[(i * y + j) * z + k] += 1;
                    }
                }
            }
        }
        
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    

    delete[] threeDarray;
    return 0;
}
