/* 
 * File:   HashTable.h
 * Author: Will
 *
 * Created on November 18, 2014, 9:25 AM
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include <cstdlib>
#include <iostream>

using namespace std;
        
class HashTable 
{
    public:
        HashTable();
        ~HashTable();
        
        void insert(int entry);
        void find(int key, bool& found, int& result); //key is value being searched for
                                                      //found is true if value is found
                                                      //result is index of data
        int size() {return used;}                     //Returns amount of array used
        void print();               //Prints out array
    
    private:
        int used;
        static const int CAPACITY = 43;                 
                
        int data[CAPACITY] = {};
        
        int hash(int data);          //Hash function to find first index value 
        int hash2(int data);         //Function to calculate increment value                 
};


#endif	/* HASHTABLE_H */

