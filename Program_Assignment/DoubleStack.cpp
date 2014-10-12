// DoubleStack.cpp

#include "DoubleStack.h"
#include <iostream>

// Default constructor, the stack is empty to start
DoubleStack::DoubleStack() {
    used = 0;
    topA = 0;
    topB = CAPACITY - 1;
    stack[CAPACITY] = {};
}


// Default destructor
DoubleStack::~DoubleStack() {
    used = 0;
    topA = 0;
    topB = 0;
    stack[CAPACITY]= {};
    // Insert your code here 
}

// Add "value" to the top of stack A
void DoubleStack::PushA(char value) {
    if (used != CAPACITY) {
        stack[topA] = value;
        topA++;
        used++;
    } else {
        throw 1;
    }
}

// Add "value" to the top of stack B
void DoubleStack::PushB(char value) {
    if (used != CAPACITY) {
        stack[topB] = value;
        topB--;
        used++;
    } else {
        throw 2;
    }
}

// Remove and return the item on the top of stack A
char DoubleStack::PopA() {
    char value;
    
    if ((used == 0) || (topA == 0)) {
        value = NULL;
        //throw 3;
    } else {
    value = stack[topA - 1];
    stack[topA - 1] = 0;
    topA--;
    used--;
    }
    
    return value; 
}

// Remove and return the item on the top of stack B
char DoubleStack::PopB() {
    char value;
    
    if ((used == 0) || (topB == CAPACITY - 1)) {
        value = NULL;
        throw 4;
    } else {
    value = stack[topB + 1];
    stack[topB + 1] = 0;
    topB--;
    used--;
    }
    
    return value; 
}

// Return the item on the top of stack A
char DoubleStack::TopA() {
    char value;
    
    if (used == 0 || topA == 0) {
        throw 3;
    } else {
    value = stack[topA - 1];
    }
    
    return value; 
}

// Return the item on the top of stack B
char DoubleStack::TopB() {
    char value;
    
    if (used == 0 || topB == 0) {
        throw 3;
    } else {
    value = stack[topB + 1];
    }
    
    return value; 
}

// Return the number of items in the stack
unsigned int DoubleStack::size() {
    return used; 
}