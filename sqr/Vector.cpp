#include "Vector.h"
#include <stdexcept>
#include <sstream>

Node* Vector::getNodeAt(size_t index) const {
    if (index >= m_size) {
        return nullptr;
    }

    Node* current = m_head;
    for (size_t i = 0; i < index; ++i) {
        current = current->m_next;
    }
    return current;
}

void Vector::clear() {
    Node* current = m_head;
    while (current != nullptr) {
        Node* next = current->m_next;
        delete current;
        current = next;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

void Vector::copyFrom(const Vector& other) {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;

    Node* current = other.m_head;
    while (current != nullptr) {
        pushBack(current->m_data);
        current = current->m_next;
    }
}

Vector::Vector()
    : m_head(nullptr), m_tail(nullptr), m_size(0) {
}

Vector::Vector(std::initializer_list<int> initList)
    : m_head(nullptr), m_tail(nullptr), m_size(0) {
    for (int value : initList) {
        pushBack(value);
    }
}

Vector::Vector(const Vector& other)
    : m_head(nullptr), m_tail(nullptr), m_size(0) {
    copyFrom(other);
}

Vector::Vector(Vector&& other) noexcept
    : m_head(other.m_head), m_tail(other.m_tail), m_size(other.m_size) {
    other.m_head = nullptr;
    other.m_tail = nullptr;
    other.m_size = 0;
}

Vector::~Vector() {
    clear();
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        clear();
        m_head = other.m_head;
        m_tail = other.m_tail;
        m_size = other.m_size;
        other.m_head = nullptr;
        other.m_tail = nullptr;
        other.m_size = 0;
    }
    return *this;
}

void Vector::pushBack(int value) {
    Node* newNode = new Node(value);

    if (m_head == nullptr) {
        m_head = newNode;
        m_tail = newNode;
    }
    else {
        m_tail->m_next = newNode;
        newNode->m_previous = m_tail;
        m_tail = newNode;
    }
    ++m_size;
}

void Vector::insertAt(size_t index, int value) {
    if (index > m_size) {
        throw std::out_of_range("Индекс вне диапазона в insertAt()");
    }

    if (index == m_size) {
        pushBack(value);
        return;
    }

    if (index == 0) {
        Node* newNode = new Node(value, m_head, nullptr);
        m_head->m_previous = newNode;
        m_head = newNode;
        ++m_size;
        return;
    }

    Node* current = getNodeAt(index);
    Node* newNode = new Node(value, current, current->m_previous);
    current->m_previous->m_next = newNode;
    current->m_previous = newNode;
    ++m_size;
}

void Vector::removeLast() {
    if (m_size == 0) {
        throw std::out_of_range("Невозможно удалить из пустого вектора");
    }

    if (m_size == 1) {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
    }
    else {
        Node* newTail = m_tail->m_previous;
        newTail->m_next = nullptr;
        delete m_tail;
        m_tail = newTail;
    }
    --m_size;
}

void Vector::removeAt(size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Индекс вне диапазона в removeAt()");
    }

    if (index == m_size - 1) {
        removeLast();
        return;
    }

    if (index == 0) {
        Node* newHead = m_head->m_next;
        newHead->m_previous = nullptr;
        delete m_head;
        m_head = newHead;
        --m_size;
        return;
    }

    Node* current = getNodeAt(index);
    current->m_previous->m_next = current->m_next;
    current->m_next->m_previous = current->m_previous;
    delete current;
    --m_size;
}

int Vector::find(int value) const {
    Node* current = m_head;
    size_t index = 0;

    while (current != nullptr) {
        if (current->m_data == value) {
            return static_cast<int>(index);
        }
        current = current->m_next;
        ++index;
    }

    return -1;
}

bool Vector::isEmpty() const {
    return m_size == 0;
}

size_t Vector::getSize() const {
    return m_size;
}

int Vector::operator[](size_t index) const {
    Node* node = getNodeAt(index);
    if (node == nullptr) {
        throw std::out_of_range("Индекс вне диапазона в operator[]");
    }
    return node->m_data;
}

int& Vector::operator[](size_t index) {
    Node* node = getNodeAt(index);
    if (node == nullptr) {
        throw std::out_of_range("Индекс вне диапазона в operator[]");
    }
    return node->m_data;
}

Vector& Vector::operator<<=(size_t positions) {
    if (positions >= m_size) {
        clear();
        return *this;
    }

    for (size_t i = 0; i < positions; ++i) {
        Node* newHead = m_head->m_next;
        newHead->m_previous = nullptr;
        delete m_head;
        m_head = newHead;
    }
    m_size -= positions;

    for (size_t i = 0; i < positions; ++i) {
        pushBack(0);
    }

    return *this;
}

Vector& Vector::operator>>=(size_t positions) {
    if (positions >= m_size) {
        clear();
        return *this;
    }

    for (size_t i = 0; i < positions; ++i) {
        Node* newTail = m_tail->m_previous;
        newTail->m_next = nullptr;
        delete m_tail;
        m_tail = newTail;
    }
    m_size -= positions;

    for (size_t i = 0; i < positions; ++i) {
        Node* newNode = new Node(0, m_head, nullptr);
        m_head->m_previous = newNode;
        m_head = newNode;
        ++m_size;
    }

    return *this;
}

std::string Vector::toString() const {
    std::ostringstream oss;
    oss << "[";

    Node* current = m_head;
    while (current != nullptr) {
        oss << current->m_data;
        if (current->m_next != nullptr) {
            oss << ", ";
        }
        current = current->m_next;
    }

    oss << "]";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Vector& vector) {
    os << vector.toString();
    return os;
}
