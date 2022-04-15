//
//  SharedSet.h
//  Homework7
//
//  Created by Cesar Caraveo on 3/16/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef SHAREDSET_H
#define SHAREDSET_H

// Shared std::set

#include <mutex>
#include <set>

template <typename T>
class SharedSet {
public:
    SharedSet() {}
    
    // Other needed methods
    void insert(std::set<T> &s);
    
    typename std::set<T>::size_type size() {
        std::lock_guard<std::mutex> lock(itemsLock);
        
        return items.size();
    }
    
private:
    std::set<T> items;
    std::mutex itemsLock;
};

template <typename T>
void SharedSet<T>::insert(std::set<T> &s) {
    std::lock_guard<T> lock(itemsLock);
    
    items.insert(s.begin(), s.end());
}

#endif
