// LinkedList.cpp

#include "LinkedList.h"

// Default constructor, the list is empty to start

LinkedList::LinkedList() {
    head_ptr = NULL;
    many_nodes = 0;
}

// Default destructor, must delete all nodes

LinkedList::~LinkedList() {
    while (head_ptr != NULL) {
        DeleteNode(many_nodes-1);
    }
}

// Add a node containing "value" to the front

void LinkedList::InsertFront(double value) {
    //Creates pointer to keep track of new node being inserted
    //into link list
    Node *insert_ptr = new Node;
    insert_ptr->data = value;
    insert_ptr->next = NULL;
    if (many_nodes == 0) {
        head_ptr = insert_ptr;
    }else{
    insert_ptr->next = head_ptr;
    head_ptr = insert_ptr;
    }
    many_nodes++;
}

// Add a node containing "value" to position "index"

void LinkedList::Insert(double value, unsigned int index) {
    if(index == 0) {
        InsertFront(value);
    }else if (index > many_nodes) {
        throw 9; 
    }else{
    Node *insert_ptr;
    unsigned int count = 0;
    
    insert_ptr = new Node;
    insert_ptr->data = value;
    insert_ptr->next = NULL;
    //Iterates through linked list to index value position
    for (cursor = head_ptr; count < index; cursor = cursor->next) {
        count++;
        precur = cursor;
        insert_ptr->next = cursor;
    }
    precur->next = insert_ptr;
    insert_ptr->next = cursor;
    
    many_nodes++;  
    } 
}


// Return value at position "index"

double LinkedList::GetNode(unsigned int index) {
    if (index >= many_nodes) {
        throw 2;
    } else {
        cursor = head_ptr;
    //Iterates through linked list to index position    
        while (index > 0) {
            cursor=cursor->next;
            index--;
        }
        
        return cursor->data;
    }
}


// Return the index of the node containing "value"

unsigned int LinkedList::Search(double value) {
    unsigned int count = 0;
    //Iterates through entire link list searching for value
    for(cursor = head_ptr; count < many_nodes; cursor=cursor->next) {
        if(value == cursor->data) {
            return count;
        } else {
            count++;
        }
    }
    throw 4;
}


// Delete the node at position "index", return the value that was there

double LinkedList::DeleteNode(unsigned int index) {
    double value;
    if (index > many_nodes) {
        throw 8;
    } else if (index == 0) {
        cursor = head_ptr->next;
        precur = head_ptr;
        value = precur->data;
        head_ptr = head_ptr->next;
        delete precur;
        many_nodes--;
        return value;
    }else{    
    unsigned int count = 0;
    cursor = head_ptr;
    //Iterates through linked list to index value
    while (count < index) {
        if (cursor->next != NULL) {
            precur = cursor;
            cursor = cursor->next;
            count++;
        } else {
            count++;
        }
    }   
        
    value = cursor->data;
    precur->next = cursor->next;
    delete cursor;
    many_nodes--;
    return value;
    }  
}

// This function reverses the order of all nodes so the first node is now the
// last and the last is now the first (and all between). So a list containing 
// (4, 0, 2, 11, 29) would be (29, 11, 2, 0, 4) after Reverse() is called.

void LinkedList::Reverse() {
    if (many_nodes == 0) {
        throw 2;
    } else {
    unsigned int count = 0;
    bool tcount = true;
    Node *tail;
    tail = new Node;
    //Iterates through linked list repeatedly 
    for (cursor = head_ptr; count < many_nodes; count++) {
        cursor = head_ptr;
        precur = cursor;
        //Iterates through link list until reaches end of list
        for (int n = 1; count < (many_nodes - n); n++) {
            precur = cursor;
            cursor = cursor->next;
        }
    //If tail pointer doesn't exist sets tail pointer to maintain pointer
    //to end of list
        if (tcount) {
            tcount = false;
            tail=cursor;
        }
        cursor->next=precur;
    }
    head_ptr = tail;
    }
}

// Return the number of nodes in the list

int LinkedList::GetLength() {
   return many_nodes; 
}
