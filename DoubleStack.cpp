// DoubleStack.cpp

#include "DoubleStack.h"
#include <iostream>

using namespace std; 

// Default constructor, the stack is empty to start
DoubleStack::DoubleStack() {
    used = 0;
    topA = 0;
    topB = CAPACITY - 1;
}


// Default destructor
DoubleStack::~DoubleStack() {
}

// Add "value" to the top of stack A
void DoubleStack::PushA(char value) {
    // Check for stack overflow
    if (used != CAPACITY) {
        stack[topA] = value;
        topA++;                 // Increment A stack index value
        used++;                 // Increment amount of array used
    } else {
        throw 1;
    }
}

// Add "value" to the top of stack B
void DoubleStack::PushB(char value) {
    // Check for stack overflow
    if (used != CAPACITY) {
        stack[topB] = value;
        topB--;                 // Decrement B stack index value
        used++;                 // Increment amount of array used
    } else {
        throw 2;
    }
}

// Remove and return the item on the top of stack A
char DoubleStack::PopA() {
    char value;
    // Check for stack underflow
    if (topA == 0) {
        throw 3;
    } else {
    value = stack[topA - 1];
    stack[topA - 1] = 'z';
    topA--;                     // Decrement A stack index value
    used--;                     // Decrement amount of array used
    }
    
    return value; 
}

// Remove and return the item on the top of stack B
char DoubleStack::PopB() {
    char value;
    // Check for stack underflow
    if (topB == CAPACITY - 1) {
        throw 4;
    } else {
    value = stack[topB + 1];
    stack[topB + 1] = 'z';
    topB++;                         // Increment B stack index value
    used--;                         // Decrement amount of array used
    }
    
    return value; 
}

// Return the item on the top of stack A
char DoubleStack::TopA() {
    char value;
    // Check for stack underflow
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
    // Check for stack underflow
    if (used == 0 || topB == CAPACITY) {
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

// Print out entire contents of stack array
void DoubleStack::printArray() {
    // Increment through array, printing contents
    for (int i = 0; i < 20; i++) {
        cout << i << " : " << stack[i] << endl;
    }
}