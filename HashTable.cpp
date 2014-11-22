//HashTable.cpp


#include "HashTable.h"

HashTable::HashTable() {
    used = 0;
}
        
HashTable::~HashTable() {
    used = 0;
}
        
void HashTable::insert(int entry) {
    int index, increment;
    
    index = hash(entry);            //Sets index value to hash function value
    if (data[index] != 0) {        //Checks if value is already at index
            data[index] = entry;    //Puts new entry into table
            used++;                 //Increments size counter
    } else {
        increment = hash2(entry);   //Calculates increment index value
        for (int k = 0; k < CAPACITY; k++) {    //Loops through table 
            index += increment;                 //Increments index appropriately
            index = index % CAPACITY;
            if (data[index] != 0) {             //If theres no value
                data[index] = entry;            //Puts value into table
                k = CAPACITY;                   //Exits loop
                used++;                         //Increments size counter
            }
        } 
    }
}

void HashTable::find(int key, bool& found, int& result) {
    int index, increment;
    
    found = false;              //Defaults found to false
    index = hash(key);          //Calculates first index value
    if (data[index] == key) {   //Checks initial index value
        found = true;           //If found returns true
        result = index;         //and the index value
    } else {
        increment = hash2(key);  //Calculates index increment value
        for (int n = 0; n < CAPACITY; n++) { //Loops through table
            index += increment;             //Increments index value
            index = index % CAPACITY;       //appropriately
            if (data[index] == key) {       //If value is at index
                result = index;             //returns index value
                found = true;               //Found set to true
                n = CAPACITY;               //Exits loop
            }
        }        
    }   
}

void HashTable::print() {
    for (int j = 0; j < CAPACITY; j++) {    //Loops through table
        cout << j << "] ";                  //Prints out index position
        if(data[j] == 0) {                  
            cout << "EMPTY" << endl;        //If data is not present, outputs EMPTY
        } else {
            cout << data[j] << endl;        //If present, outputs data value
        }
    }
}

int HashTable::hash(int data) {     //Calculates initial index value
    int hashValue;
    hashValue = (data % 42); //mod 42
    
    return hashValue;
}
        
int HashTable::hash2(int data) {    //Calculates value to increment index by
    int hashValue;
    
    hashValue = (data % 5);  //mod 5
    
    return hashValue;
}

