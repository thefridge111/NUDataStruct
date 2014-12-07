/* 
 * File:   main.cpp
 * Author: Will
 *
 * Created on December 2, 2014, 10:22 AM
 */

#include <cstdlib>
#include "../sorting.h"
#include <iostream>
#include <string>

using namespace std;

void runTest(int data[], int resetdata[], int n);
void print(int data[], int n, string sortType);
void reset(int data[], int data1[], int n);

int main() {
    int n = 12;
    int a[12] = { 13, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int b[12] = { 15, 48, 32, 46, 33, 19, 57, 16, 24, 30, 39, 47 };
    int c[12] = { 27, 19, 26, 48, 16, 50, 56, 30, 13, 44, 53, 22 };
    int d[12] = { 9, 39, 2, 22, 8, 53, 46, 59, 15, 38, 14, 44 };
    int e[12] = { 29, 59, 35, 2, 13, 36, 31, 9, 3, 1, 20, 24 };
    
    int a1[12] = { 13, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int b1[12] = { 15, 48, 32, 46, 33, 19, 57, 16, 24, 30, 39, 47 };
    int c1[12] = { 27, 19, 26, 48, 16, 50, 56, 30, 13, 44, 53, 22 };
    int d1[12] = { 9, 39, 2, 22, 8, 53, 46, 59, 15, 38, 14, 44 };
    int e1[12] = { 29, 59, 35, 2, 13, 36, 31, 9, 3, 1, 20, 24 };
   
    runTest(a1, a, 12);
    runTest(b1, b, 12);
    runTest(c1, c, 12);
    runTest(d1, d, 12);
    runTest(e1, e, 12);
    
    return 0;
} 

void runTest(int data[], int resetdata[], int n) {
    int swap = 0;
    
    print(data, n, "No Sort");
        
    swap = insertionsort(data, n);
    print(data, n, "Insertion Sort");
    cout << "Swaps: " << swap << endl;
    swap = 0;
    reset(data, resetdata, n);
    
    swap = heapsort(data, n);
    print(data, n, "Heap Sort");
    cout << "Swaps: " << swap << endl;
    swap = 0;
    reset(data, resetdata, n);
        
    swap = quicksort(data, n);
    print(data, n, "Quicksort");
    cout << "Swaps: " << swap << endl;
    swap = 0;
    reset(data, resetdata, n);
}

void reset(int data[], int data1[], int n) {
    for(int i = 0; i < n; i++) {
        data[i] = data1[i];
    }
}

void print(int data[], int n, string sortType) {
    cout << "Array after " << sortType << ": ";
    cout << "{";
    for (int k = 0; k < n; k++) {
        cout << data[k] << ", ";
    }
    cout << "}" << endl;
}