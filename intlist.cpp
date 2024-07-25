// intlist.cpp
// Implements class IntList
// Elizabeth Sanchez 07/21/24
#include "intlist.h"
#include <iostream>
using std::cout;

// constructor
IntList::IntList() : first(nullptr) {}

// destructor deletes all nodes
IntList::~IntList() {
    while (first != nullptr) {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
}

// copy constructor
IntList::IntList(const IntList& source) : first(nullptr) {
    if (source.first == nullptr) return;

    first = new Node;
    first->info = source.first->info;
    Node *current = first;
    Node *sourceNode = source.first->next;
    while (sourceNode != nullptr) {
        current->next = new Node;
        current = current->next;
        current->info = sourceNode->info;
        sourceNode = sourceNode->next;
    }
    current->next = nullptr;
}

// append value at end of list
void IntList::append(int value) {
    if (first == nullptr) {
        first = new Node;
        first->info = value;
        first->next = nullptr;
    } else {
        Node *n = first;
        while (n->next) {
            n = n->next;
        }
        n->next = new Node;
        n->next->info = value;
        n->next->next = nullptr;
    }
}

// print values enclosed in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next) cout << ' ';
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}

// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node *current = first;
    while (current != nullptr) {
        total += current->info;
        current = current->next;
    }
    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *current = first;
    while (current != nullptr) {
        if (current->info == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (first == nullptr) {
        return 0;
    }
    int maxValue = first->info;
    Node *current = first->next;
    while (current != nullptr) {
        if (current->info > maxValue) {
            maxValue = current->info;
        }
        current = current->next;
    }
    return maxValue;
}

// returns average (arithmetic mean) of all values, or 0 if list is empty
double IntList::average() const {
    if (first == nullptr) {
        return 0.0;
    }
    int total = sum();
    int count = this->count();
    return static_cast<double>(total) / count;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node *newNode = new Node;
    newNode->info = value;
    newNode->next = first;
    first = newNode;
}

// assignment operator
IntList& IntList::operator=(const IntList& source) {
    if (this == &source) {
        return *this;
    }

    // Delete the current list
    while (first != nullptr) {
        Node *temp = first;
        first = first->next;
        delete temp;
    }

    // Copy the source list
    if (source.first == nullptr) {
        first = nullptr;
    } else {
        first = new Node;
        first->info = source.first->info;
        Node *current = first;
        Node *sourceNode = source.first->next;
        while (sourceNode != nullptr) {
            current->next = new Node;
            current = current->next;
            current->info = sourceNode->info;
            sourceNode = sourceNode->next;
        }
        current->next = nullptr;
    }

    return *this;
}
