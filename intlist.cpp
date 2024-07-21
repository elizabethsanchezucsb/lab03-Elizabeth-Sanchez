#include "intlist.h"
#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) : first(nullptr) {
    if (source.first == nullptr) {
        return; // Source list is empty
    }
    // Copy the first node
    first = new Node;
    first->info = source.first->info;

    // Copy the rest of the nodes
    Node *current = first;
    Node *sourceNode = source.first->next;
    while (sourceNode != nullptr) {
        current->next = new Node;
        current = current->next;
        current->info = sourceNode->info;
        sourceNode = sourceNode->next;
    }
    current->next = nullptr; // End the list
}

// destructor deletes all nodes
IntList::~IntList() {
    while (first != nullptr) {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
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
        return 0; // Empty list
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
        return 0.0; // Empty list
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
        return *this; // Self-assignment, do nothing
    }

    // Delete the current list
    while (first != nullptr) {
        Node *temp = first;
        first = first->next;
        delete temp;
    }

    // Copy the source list
    if (source.first == nullptr) {
        first = nullptr; // Source list is empty
    } else {
        // Copy the first node
        first = new Node;
        first->info = source.first->info;

        // Copy the rest of the nodes
        Node *current = first;
        Node *sourceNode = source.first->next;
        while (sourceNode != nullptr) {
            current->next = new Node;
            current = current->next;
            current->info = sourceNode->info;
            sourceNode = sourceNode->next;
        }
        current->next = nullptr; // End the list
    }

    return *this;
}
