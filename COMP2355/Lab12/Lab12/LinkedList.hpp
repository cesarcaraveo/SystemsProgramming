//
//  LinkedList.hpp
//  Lab12
//
//  Created by Cesar Caraveo on 2/16/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

template <typename T>
struct Node {
    T item;
    Node<T>* next;
};

template <typename T>
class LinkedList {
public:
    LinkedList(); // default constructor, initialize head pointer to null
    ~LinkedList();
    bool isEmpty();
    void insertAtHead(T v); // insert v at head
    T peekHead();
    T removeHead();
    void print(); // print linked list starting at head
    
private:
    Node<T> *head; // Node pointer to the head of the list
};

template <typename T>
LinkedList<T>::LinkedList() { // default constructor, initialize head pointer to null
    head = nullptr; // set head to null
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *n = head; // temp variable that references head of list
    Node<T> *temp = head;
    
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
bool LinkedList<T>::isEmpty() {
    bool empty = false;
    
    if (*head == nullptr) {
        empty = true;
    }
    
    return empty;
}

template <typename T>
void LinkedList<T>::insertAtHead(T v) { // insert v at head
    Node<T> *n = new Node<T>{v, head}; // create new node on heap with value v and point to head
    head = n; // update head
}

template <typename T>
T LinkedList<T>::peekHead() {
    return *head;
}

template <typename T>
T LinkedList<T>::removeHead() {
    Node<T> *temp = head;

    if (head != nullptr) {
        head = head->next;
    }
    
    T val = temp->item;
    delete temp;
    return val;
}

template <typename T>
void LinkedList<T>::print() { // print linked list starting at head
    Node<T> *n = head; // temp variable that references head of list
    
    if (n != nullptr) { // if head is not null
        while (n->next != nullptr) { // while node is not last one
            std::cout << n->item << " "; // print the node
            n = n->next; // move the temp variable to the next node
        }
        
        std::cout << n->item << " "; // print last node
    }
}

#endif /* LinkedList_hpp */
