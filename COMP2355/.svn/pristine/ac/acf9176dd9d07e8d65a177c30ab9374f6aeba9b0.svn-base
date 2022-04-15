//
//  LinkedList.cpp
//  Lab10
//
//  Created by Cesar Caraveo on 2/9/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include "LinkedList.hpp"

LinkedList::LinkedList() { // default constructor, initialize head pointer to null
    head = nullptr; // set head to null
}

void LinkedList::insertAtHead(int v) { // insert v at head
    Node *n = new Node(v, head); // create new node on heap with value v and point to head
    head = n; // update head
}

void LinkedList::printList() { // print linked list starting at head
    Node *n = head; // temp variable that references head of list
    
    if (n != nullptr) { // if head is not null
        while (n->GetNext() != nullptr) { // while node is not last one
            n->PrintNode(); // print the node
            n = n->GetNext(); // move the temp variable to the next node
        }
        
        n->PrintNode(); // print last node
    }
}

void LinkedList::freeList() { // delete all memory allocated for nodes
    Node *n = head; // temp variable that references head of list
    Node *temp = head;

    if (n != nullptr) { // if head is not null
        while (n->GetNext() != nullptr) { // while the node in question is not the last one
            n->SetValue(0); // set value to 0
            temp = n->GetNext(); // set n to next node
            delete n; // delete node
            n = temp;
        }

        // delete last one
        n->SetValue(0); // set value to 0
        temp = nullptr; // next is set to null
        delete n; // delete node
        n = nullptr; // n is set to null
        head = nullptr;
    }
}

