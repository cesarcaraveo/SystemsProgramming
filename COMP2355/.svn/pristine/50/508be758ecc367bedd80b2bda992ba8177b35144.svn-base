//
//  SharedQueue.h
//  Homework7
//
//  Created by Cesar Caraveo on 3/16/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef SharedQueue_h
#define SharedQueue_h

// Shared std::set

#include <mutex>
#include <list>

template <typename T>
class SharedQueue {
public:
    SharedQueue() {}
    
    // Other needed methods
    void add(T item);
    bool remove(T &item);
    
    typename std::list<T>::size_type size() {
        std::lock_guard<std::mutex> lock(itemsLock);
        
        return items.size();
    }
    
private:
    std::list<T> items;
    std::mutex itemsLock;
};

template <typename T>
void SharedQueue<T>::add(T item) {
    std::lock_guard<T> lock(itemsLock);
    items.push_front(item);
}

template <typename T>
bool SharedQueue<T>::remove(T &item) {
    std::lock_guard<T> lock(itemsLock);
    
    if (items.size() == 0) {
        return false;
    }
    
    item = items.back();
    item.pop_back();
    
    return true;
}

#endif /* SharedQueue_h */
