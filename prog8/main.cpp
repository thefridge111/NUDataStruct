/*Sorting project main:  
 * Heap sort
 * Insertion sort   
 * Quicksort 
 *
 * Written by Will Perry
 * IS228
 * December 2014
 */

#include <cstdlib>
#include "../sorting.h"
#include <iostream>
#include <string>

using namespace std;

void runTest(int data[], int resetdata[], int n); //Runs all sorting algorithms
void print(int data[], int n, string sortType); //Prints arrays
void reset(int data[], int data1[], int n); //Resets copies of array to original values

int main() {
    //Original arrays to be sorted, only used as reset values
    //in practice
    int a[12] = { 13, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int b[12] = { 15, 48, 32, 46, 33, 19, 57, 16, 24, 30, 39, 47 };
    int c[12] = { 27, 19, 26, 48, 16, 50, 56, 30, 13, 44, 53, 22 };
    int d[12] = { 9, 39, 2, 22, 8, 53, 46, 59, 15, 38, 14, 44 };
    int e[12] = { 29, 59, 35, 2, 13, 36, 31, 9, 3, 1, 20, 24 };
    
    //Copies of a,b,c,d,e to be sorted
    int a1[12] = { 13, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int b1[12] = { 15, 48, 32, 46, 33, 19, 57, 16, 24, 30, 39, 47 };
    int c1[12] = { 27, 19, 26, 48, 16, 50, 56, 30, 13, 44, 53, 22 };
    int d1[12] = { 9, 39, 2, 22, 8, 53, 46, 59, 15, 38, 14, 44 };
    int e1[12] = { 29, 59, 35, 2, 13, 36, 31, 9, 3, 1, 20, 24 };
   
    //Run tests on all arrays
    runTest(a1, a, 12);
    runTest(b1, b, 12);
    runTest(c1, c, 12);
    runTest(d1, d, 12);
    runTest(e1, e, 12);
    
    return 0;
} 

//data[] is the array being sorted
//resetdata[] is the array data[] will be set back to after each sort
//n is the length of the two arrays
void runTest(int data[], int resetdata[], int n) {
    int swap = 0; //Keeps tracks of swaps, set to 0 after each sort
    
    print(data, n, "No Sort"); //Print data initial value
    
    //Test insertion sort
    swap = insertionsort(data, n);
    print(data, n, "Insertion Sort");
    cout << "Swaps: " << swap << endl;
    swap = 0;
    reset(data, resetdata, n);
    
    //test heapsort
    swap = heapsort(data, n);
    print(data, n, "Heap Sort");
    cout << "Swaps: " << swap << endl;
    swap = 0;
    reset(data, resetdata, n);
    
    //Test quicksort    
    swap = quicksort(data, n);
    print(data, n, "Quicksort");
    cout << "Swaps: " << swap << endl;
    swap = 0;
    reset(data, resetdata, n);
    
    cout << endl;
}

//data[] values are set to data1[] values
//n is length of arrays
void reset(int data[], int data1[], int n) {
    for(int i = 0; i < n; i++) {
        data[i] = data1[i];
    }
}

//data[] is the array to be printed
//n is length of array
//sortType is the heading to notify user of sort just performed
void print(int data[], int n, string sortType) {
    //Outputs in set notation
    cout << "Array after " << sortType << ": ";
    cout << "{";    
    for (int k = 0; k < n; k++) {
        cout << data[k] << ", ";
    }
    cout << "}" << endl;
}