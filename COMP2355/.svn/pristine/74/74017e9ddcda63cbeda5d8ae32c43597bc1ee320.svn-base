#include <iostream>
#include <stdint.h>
#include "PackedArray.h"

// Create the array; initialize memory
PackedArray CreateArray(int aSize) {
    int numOfRows = (aSize / 32) + 1; // 32 entries per 64 bits. add one to get amt of 64 bit entries (rows)
    uint64_t *arr = new uint64_t[numOfRows]; // pointer to array (packedarray)

    PackedArray p;
    p.numRows = numOfRows;
    p.rows = &arr[0]; // references beginning of array
    
    for (int i = 0; i < numOfRows; i++) { // initialize memory
        arr[i] = 0;
    }
    
    return p;
}


// Frees memory for the array
void FreeArray(PackedArray &array) {
    delete &array;
}


// Sets all entries in the array to value parameter
void FillArray(PackedArray &array, uint64_t value) {
    for (int i = 0; i < array.numRows; i++) {
        for (int j = 0; j < 32; j++) {
            SetEntry(array, i, j, value);
        }
    }
}

// Clears all entries to 0 in the array
void ClearArray(PackedArray &array) {
    uint64_t *indexArray = array.rows; // pointer to array
    for (int i = 0; i < array.numRows; i++) {
        *indexArray = 0x0;
        indexArray++;
    }
}

// Get the value of the entry at the specified row and col.
// If row or col are outside of the range for this PackedArray,
// returns 0.
int GetEntry(const PackedArray &array, int row, int col) {
    if (col > 31 && col < 0) {
        std::cout << "Column outside of range";
        return 0;
    }
    
    if (row < 0 && row > array.numRows) {
        std::cout << "Row outside of range";
        return 0;
    }
    
    int shift = col * 2;
    uint64_t mask = 0x3 << shift;
    uint64_t value = *array.rows & mask;
    value = value >> shift;
    
    return value;
}

// Sets entry in the location row, col to the specified value.
// If row or col are outside of the range for this PackedArray,
// function has no effect.
void SetEntry(PackedArray &array, int row, int col, uint64_t value) {
    if (col >= 0 && col <= 31 && row >= 0 && row <= array.numRows) {
        int shift = col * 2;
        uint64_t mask = value << shift;
        value = *array.rows | mask;
    }
}

// Sum all the entries in the array
int SumEntries(const PackedArray &array) {
    int sum = 0;
    for (int i = 0; i < array.numRows; i++) {
        for (int j = 0; j < 32; j++) {
            sum += GetEntry(array, i, j);
        }
    }
    
    return sum;
}
