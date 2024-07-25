// intlist.cpp
// Implements class IntList
// Elizabeth Sanchez 07/21/24

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) { //CREATES new object (source) as a copy of other object (IntList!!).. (copy constructor needs to create same linked list with same elements so it will become source list
    //IMPLEMENT THIS at end.
    if (source.first == nullptr){ //if linked list empty in intList just return thats the copy?.
        return;
    }
    else{
        source.first = first->info;
        source.first->next = 
    }

}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node *current = first;
    while(current){ //while there is a node
        sum += current->info;
        current = current->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = first;
    while(n != nullptr){
        if(n->info == value){
            return true;
        }
         n = n->next;
    }
        // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(first == nullptr){
        return 0; 
    }
    Node *curr = first;
    int max = curr->info;
    while(curr != nullptr){
        if(curr->info > max){
            max = curr->info;
        }
        curr = curr->next;
        }
        return max;
    }
    
// REPLACE THIS NON-SOLUTION

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    
    
    if(cur == nullptr){
        return 0.0;
    }
    Node *cur = first;
    int count = 0;
    int sum = 0;
    while(cur != nullptr){
        sum+= cur->info;
        count++; 
        cur = cur->next;
    }

    return static_cast<double>(sum)/count; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    // IMPLEMENT
    Node *nn = new Node;
    nn->info = value;
    nn->next = first;
    first = nn;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) { //while we have a node, increase the count (result) and move on to next
        ++result;
        n = n->next;
    }
    return result;
}
