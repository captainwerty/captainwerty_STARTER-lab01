// intlist.cpp
// Implements class IntList
// Harsha Malaviya 1/11/26

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;
    *this = source;
    
    //IMPLEMENT THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = head;
    while(curr){
        sum+=curr->info;
        curr = curr ->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while(curr){
        if(curr->info == value){ return true;}
        curr = curr ->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(!head) return 0;
    int max = head->info;
    Node* curr = head;
    while(curr){
        if(curr->info>max) max = curr->info;
        curr = curr ->next;
    }

    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(!head) return 0;
    int num = this->count();
    int sum = this->sum();

    return static_cast<double>(sum) / num;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* new_node = new Node();
    new_node->info = value;
    if(!head){
        head = new_node;
        tail = new_node;
    }else if(!head->next){
        new_node->next = head;
        head = new_node;
    } else {
        new_node->next = head->next;
        head->next = new_node;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node *new_node = new Node();
    new_node->info = value;
    if (tail){
        tail->next = new_node;
        tail = new_node;
    } else {
        head = new_node;
        tail = new_node;
    }
}

// return count of values
int IntList::count() const {
    if(!head) return 0;
    int i = 0;
    Node* curr = head;
    while(curr){
        i++;
        curr = curr ->next;
    }
   //IMPLEMENT THIS
   return i;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;

    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;

    curr = source.head;
    while (curr) {
        push_back(curr->info);
        curr = curr->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList():head(nullptr),tail(nullptr){ }

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

