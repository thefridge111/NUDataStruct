/* 
 * File:   main.cpp
 * Author: Will
 *
 * Created on November 18, 2014, 9:25 AM
 */

#include <cstdlib>
#include <iostream>
#include "../HashTable.h"

using namespace std;

int main() {
    int value, result;
    bool found;
    
    HashTable A;
    
    value = 55;
    for (int i = 1; i < 21; i++) {      //Populates table with multiples of 55
        A.insert(value * i); 
    } 
        
    A.print();                          //Tests prints function
    
    value = A.size();
    cout << "Size is: " << value << endl;   //Tests size function
    
    //Code below tests that find works appropriately. Test values are reset
    //before each function call so as to ensure that values are being modified
    //appropriately.
    value = 165;
    result = 100;
    found = false;
    
    A.find(value, found, result);
    cout << "Value: " << value << endl;
    if (found) {
        cout << "Found: True" << endl;
    } else {
        cout << "Found: False" << endl;
    }
    cout << "Found at index: " << result << endl;
    
    value = 131;
    result = 100;
    found = false;
    
    A.find(value, found, result);
    cout << "Value: " << value << endl;
    if (found) {
        cout << "Found: True" << endl;
    } else {
        cout << "Found: False" << endl;
    }
    cout << "Found at index: " << result << endl;
    
    value = 1045;
    result = 100;
    found = false;
    
    A.find(value, found, result);
    cout << "Value: " << value << endl;
    if (found) {
        cout << "Found: True" << endl;
    } else {
        cout << "Found: False" << endl;
    }
    cout << "Found at index: " << result << endl;
    
    return 0;
}

