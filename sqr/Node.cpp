#include "Node.h"

Node::Node()
    : m_data(0), m_next(nullptr), m_previous(nullptr) {
}

Node::Node(int data, Node* next, Node* previous)
    : m_data(data), m_next(next), m_previous(previous) {
}

Node::~Node() {
    m_next = nullptr;
    m_previous = nullptr;
}

int Node::getData() const {
    return m_data;
}

const Node* Node::getNext() const {
    return m_next;
}

const Node* Node::getPrevious() const {
    return m_previous;
}
