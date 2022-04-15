//
//  SharedQueue.h
//  Lab14
//
//  Created by Cesar Caraveo on 2/23/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef SHAREDQUEUE_H
#define SHAREDQUEUE_H

#include <mutex>
#include <iostream>

template <typename T> class SharedQueue {
public:
    SharedQueue();
    ~SharedQueue();
    
    /*
     These declarations mean that we do NOT get the automatically
     defined copy/copy-assign functions.  If you try to call one
     by copying the queue, you'll get a compiler error.
     
     This is a common technique for things that are uncopyable (like std::thread
     and std::mutex, for example).
     
     We really DO want a destructor, so cheating at the
     rule of 3 here makes sense here.
     */
    SharedQueue(const SharedQueue<T> &) = delete;
    SharedQueue<T> &operator=(const SharedQueue<T> &) = delete;
    
    // Return true if the queue is empty
    bool IsEmpty() const;
    
    // Enqueue the next item at the tail of the queue.
    void Add(T value);
    
    // Dequeue the next queue element and store it in "item" variable.  The
    // function returns false if the queue is empty and no item can be retrieved.
    bool Remove(T &item);
    void Print();
    
private:
    struct QueueItem {
        T item;
        QueueItem *next;
    };
    
    // Fill in the The private data members.
    QueueItem *head;
    QueueItem *tail;
    std::mutex lock;
};

// Fill in the function definitions
template <typename T>
SharedQueue<T>::SharedQueue() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
SharedQueue<T>::~SharedQueue() {
    QueueItem *n = head; // temp variable that references head of list
    QueueItem *temp = head;
    
    if (n != nullptr) { // if head is not null
        while (n->next != nullptr) { // while the node in question is not the last one
            temp = n->next; // set n to next node
            delete n; // delete node
            n = temp;
        }
        
        // delete last one
        temp = nullptr; // next is set to null
        delete n; // delete node
        n = nullptr; // n is set to null
        head = nullptr;
    }
}

template <typename T>
bool SharedQueue<T>::IsEmpty() const {
    return (head == nullptr);
}

template <typename T>
void SharedQueue<T>::Add(T value) {
    lock.lock();
    
    QueueItem *addedValue = new QueueItem();
    addedValue->item = value;
    addedValue->next = nullptr;
    
    if (head == nullptr) {
        head = addedValue;
        tail = addedValue;
    }
    
    else {
        tail->next = addedValue;
        tail = addedValue;
    }
    
    lock.unlock();
}

template <typename T>
bool SharedQueue<T>::Remove(T &item) {
    lock.lock();
    
    if (!IsEmpty()) {
        item = head->item;
        QueueItem *tmp = head;
        head = head->next;
        delete tmp;
        lock.unlock();
        
        return true;
    }
    
    lock.unlock();
    
    return false;
}

template <typename T>
void SharedQueue<T>::Print() {
    for (QueueItem *n = head; n; n = n->next)
        std::cout << n->item << " ";
    std::cout << "\n";
}

#endif

