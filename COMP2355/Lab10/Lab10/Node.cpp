#include "Node.h"
#include <iostream>

Node::Node(int v, Node *n) : value(v), nextNode(n) {} // initializer list, assings v to value, n to nextNode

void Node::SetValue(int v) {
    value = v;
}

void Node::SetNext(Node *n) {
    nextNode = n;
}

int Node::GetValue() const {
    return value;
}

Node *Node::GetNext() const {
    return nextNode;
}

void Node::PrintNode() {
    std::cout << "(" << value << ")";
}
