//
//  MyArray.h
//  Homework6
//
//  Created by Cesar Caraveo on 3/7/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef MyArray_h
#define MyArray_h

template <typename T>
class MyArray {
public:
    // constructor, param for size of array (default is 0)
    // size is number of elements in array not size of storage used internally
    // default internal size is 20, if more needed, then set to size param
    MyArray(int size = 0);
    // rule of three
    ~MyArray(); // destructor
    MyArray(const MyArray &other); // copy constructor
    MyArray &operator=(const MyArray &other); // assignment operator
    T& get(int index); // get method
    void set(int index, T value); // set method
    int size(); // method to return size of array
    void resize(int newSize); // resize method (if size is larger, copy items, new items are uninitialized
    void pushBack(T value); // pushback method; add to end of array. increase size by 1. resize array if internal mem was small
    T back(); // back method; returns last element in array
    void popBack(); // popback method; removes last element in array. (internal mem will not shrink)
private:
    int internalSize;
    int externalSize;
    T *array;
};

template <typename T>
MyArray<T>::MyArray(int size) {
    // constructor, param for size of array (default is 0)
    // size is number of elements in array not size of storage used internally
    // default internal size is 20, if more needed, then set to size param
    if (size <= 20) {
        internalSize = 20;
        array = new T[internalSize];
    }
    
    else {
        internalSize = size;
        array = new T[internalSize];
    }
    
    externalSize = size;
}

// rule of three
template <typename T>
MyArray<T>::~MyArray() { // destructor
    delete[] array;
    array = nullptr;
}


template <typename T>
MyArray<T>::MyArray(const MyArray<T> &other) { // copy constructor
    array = new T[other.size()];
    
    for (int i = 0; i < other.size(); i++) {
        array[i] = other.array[i];
    }
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T> &other) { // assignment operator
    T temp = new T[other.size()];
    
    for (int i = 0; i < other.size(); i++) {
        temp[i] = other.array[i];
    }
    
    delete[] array;
    array = temp;
    
    return *this;
}

template <typename T>
T& MyArray<T>::get(int index) { // get method
    return array[index];
}

template <typename T>
void MyArray<T>::set(int index, T value) { // set method
    array[index] = value;
}

template <typename T>
int MyArray<T>::size() { // return size of array
    return externalSize;
}

template <typename T>
void MyArray<T>::resize(int newSize) {
    // resize method (if size is larger, copy items, new items are uninitialized
    // if not the same size
    if (newSize != size()) {
        // if shrinking
        if (newSize < size()) {
            // create temp bitmap
            T *temp = new T[newSize];
            
            // copy values up to newSize to temp
            for (int i = 0; i < newSize; i++) {
                temp[i] = array[i];
            }
            
            // update bitmap
            delete[] array;
            array = temp;
            
            internalSize = newSize; // update size
        }
        
        // if expanding
        else {
            // create temp bitmap
            T *temp = new T[newSize];
            
            // copy values up to old size to temp
            for (int i = 0; i < size(); i++) {
                temp[i] = array[i];
            }
//
//            // zero new space
//            for (int i = size(); i < newSize; i++) {
//                temp[i] = 0x0;
//            }
//
            // update bitmap
            delete[] array;
            array = temp;
            
            internalSize = newSize; // update size
        }
    }
}

template <typename T>
void MyArray<T>::pushBack(T value) {
    // pushback method; add to end of array. increase size by 1. resize array if internal mem was small
    if (externalSize < internalSize) {
        array[externalSize] = value;
        externalSize++;
    }
    
    else {
        resize(size() * 2);
        array[externalSize] = value;
        externalSize++;
    }
}

template <typename T>
T MyArray<T>::back() { // back method; returns last element in array
    return array[externalSize - 1];
}

template <typename T>
void MyArray<T>::popBack() {
    // popback method; removes last element in array. (internal mem will not shrink)
    externalSize--;
}

#endif /* MyArray_h */
