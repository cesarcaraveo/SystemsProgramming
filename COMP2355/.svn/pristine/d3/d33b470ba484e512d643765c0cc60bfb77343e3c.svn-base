//
//  main.cpp
//  Lab13
//
//  Created by Cesar Caraveo on 2/21/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include "Timer.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <thread>

// InitValues - set array values.  Array items are
//   set to the sqrt of their index in the array.
//
// a - pointer to first item to set
// first - index of first array item to set
// last - index of the array item one past the last item to set
void InitValues(double *a, int first, int last) {
    for (int i = first; i < last; ++i) {
        a[i] = sqrt((double)i);
    }
}

// SumValues - sum array values.
//
// a - array to be summed
// sum - return value, the sum of all items in the range
// first - index of first array item to be summed
// last - index of the array item one past the last item to set
void SumValues(const double *a, double *sum, int first, int last) {
    double sumTmp = 0.0;
    for (int i = first; i < last; ++i) {
        sumTmp += a[i];
    }
    *sum = sumTmp;
}

// ThreadedSum - initialize and sum a large array using
//   multiple threads.
//
// numThreads - number of threads to use
// arraySize - size of array to use
double ThreadedSum(int numThreads, size_t arraySize) {
    double sum = 0.0;
    
    // ********************
    // Write your code here
    // ********************
    
    // 1) Allocate an array on the heap of type double with arraySize elements .
    // This may get too large for the stack, so make sure you allocate it on the
    // heap (free store).
    
    double *array = new double[arraySize];
    
    // 2) Run numThreads threads, each of which initializes an approximately equal
    // portion of the array. For  example, if numThreads is 8, each thread should
    // initialize ⅛ of the array. Make sure you handle round-off correctly if
    // arraySize is not an even multiple of numThreads.
    
    int ceiling = ((int)arraySize + numThreads - 1) / numThreads; // ceiling of number of threads
    int floor = (int)arraySize / numThreads;
    
    std::thread *threads[numThreads]; // creates array of threads
    for (int i = 0; i < numThreads - 1; i++) { // goes through all but last thread
        threads[i] = new std::thread(InitValues, array, i * ceiling, (i + 1) * ceiling); // equal amounts
    }
    
    threads[numThreads - 1] = new std::thread(InitValues, array, arraySize - floor, arraySize); // last thread
    
    // 3) Wait for all of the initialization threads to complete, and delete the
    // threads.
    
    for (int i = 0; i < numThreads; i++) {
        threads[i]->join();
        delete threads[i];
        threads[i] = nullptr;
    }
    
    // 4) Run numThreads new threads, each of which computes the sum of all the
    // elements in an equal portion of the array.
    
    double sums[numThreads];
    
    std::thread *threadsSum[numThreads]; // creates array of threads
    for (int i = 0; i < numThreads - 1; i++) { // goes through all but last thread
        threadsSum[i] = new std::thread(SumValues, array, &sums[i], i * ceiling, (i + 1) * ceiling); // equal amounts
    }
    
    threadsSum[numThreads - 1] = new std::thread(SumValues, array, &sums[numThreads - 1], arraySize - floor, arraySize); // last thread
    
    // 5) Wait for all of the sum threads to complete.
    
    for (int i = 0; i < numThreads; i++) {
        threadsSum[i]->join();
    }
    
    // 6) Add up all the partial sums, and compute the total. You can find some
    // sample totals for different array sizes below.
    
    for (int i = 0; i < numThreads; i++) {
        sum += sums[i];
    }
    
    // 7) Release the storage allocated for the array, as well as any other heap
    // storage that you’ve used.
    
    for (int i = 0; i < numThreads; i++) {
        delete threadsSum[i];
        threadsSum[i] = nullptr;
    }
    
    return sum;
}

int main(int argc, const char *argv[]) {
    // Use the number of hardware threads provided by the CPU(s).
    // If only one hardware thread, use two threads.
    int numThreads = std::thread::hardware_concurrency();
    std::cout << "Hardware threads available: " << numThreads << std::endl;
    if (numThreads < 2)
        numThreads = 2; // use at least 2 threads
    
    // Create a Timer object
    Timer t;
    
    // Run for each power of 2 from 20 to 26 (You may want to start
    // with 10 to 15 for testing)
    for (int power = 20; power <= 26; power++) {
        t.StartTimer();
        double sum1 = ThreadedSum(1, 1 << power);
        t.EndTimer();
        std::cout << "Elapsed time: " << t.GetElapsedTime() << ", "
        << "arraySize " << (1 << power)
        << ", numThreads = 1, sum = " << std::setprecision(15) << sum1
        << std::endl;
        
        t.StartTimer();
        double sumN = ThreadedSum(numThreads, 1 << power);
        t.EndTimer();
        std::cout << "Elapsed time: " << t.GetElapsedTime() << ", "
        << "arraySize " << (1 << power) << ", numThreads = " << numThreads
        << ", sum = " << std::setprecision(15) << sumN << std::endl;
    }
}

