/*Sorting project source:  
 * Heap sort
 * Insertion sort   
 * Quicksort 
 *
 * Written by Will Perry
 * IS228
 * December 2014
 */


#include "sorting.h"
#include <iostream>

int heapsort(int data[], unsigned int n) {  
    int unsorted, swaps;        //Unsorted used as a counter while array isnt sorted
    swaps = 0;                  //Swaps is a counter for number of times elements are swapped during sort
    
    swaps += make_heap(data, n);         //Makes a heap of length n
    
    unsorted = n;               //unsorted starts as length of array
    
    while(unsorted > 1) {       //While there are still elements left to be sorted
        unsorted--;             //Decrement unsorted
        swap(data[0], data[unsorted]);  //Moves first (largest) element to the end of the array
        swaps++;                //Increments swaps
        swaps += reheapify_down(data, unsorted);    //Makes sure largest element is at the top of the heap
    }
    
    return swaps;               //Returns number of swaps 
}

int make_heap(int data[], int n) {
    int k, swaps;               //k to keep track of index position within heap
    swaps = 0;                  //Swaps counter for number of swaps when building tree
    
    for (int i = 1; i < n; i++) {  //Checks that values are at corrects location within heap
        k = i;                      //Start index at i
        while ((data[k] > data[parent(k)]) && (k > 0)) {  //while child is larger than parent and not checking root node
            swap(data[k], data[parent(k)]);               //swap child with parent 
            swaps++;                //increment swap counter
            k = parent(k);          //set k to parent index
        }
    }
    return swaps;               //return swaps
}

int parent(int k) {
    return ((k - 1) / 2);       //Parent can be found at (k - 1) / 2
}

void swap(int& data, int& unsorted){
    int temp;           //Temp value stores one of the values to be swapped
    
    temp = data;        //set temp to one of the values
    data = unsorted;    //data is set to unsorted
    unsorted = temp;    //unsorted is set to temp
}

int reheapify_down(int data[], int n) {
    int current, swaps = 0;                     //current is value being checked
    int big_child_index, rightChild, leftChild; //if node is partent, big_child_index is index value of larger child
                                //rightChild and leftChild keep track of children values
    bool heap_ok;               //flag to exit while loop
    
    current = 0;                //Start at beginning of heap
    heap_ok = false;            //heap begins not complete
    
    while ((!heap_ok) && (((current * 2) + 1) < n)) {   //while heap isnt complete and the child location of
                                                        //current does not exceed array
        rightChild = right_child(current);      //rightChild and leftChild values are computed
        leftChild = left_child(current);
        
        if((leftChild < n) && (rightChild < n)) {       //Determines which child value is larger
            if (data[leftChild] > data[rightChild]) {   //and sets big_child_index to the larger
                big_child_index = leftChild;            //child's index value
            } else {
                big_child_index = rightChild;
            }
        } else {
            big_child_index = leftChild;
        }
        
        if (data[current] < data[big_child_index]) {    //if current index positions value is smaller than
            swap(data[current], data[big_child_index]); //its child's value then swap largest child and 
            swaps++;                                    //parent values, increment swaps.
            current = big_child_index;                  //current then becomes location of the parent's new index 
        } else {
            heap_ok = true;                             //otherwise heap is complete
        }
    }
    return swaps;                   //return swaps
}

int left_child(int index) {
    return ((index * 2) + 1);       //Left child is found at (index * 2) + 1
}

int right_child(int index) {
    return ((index * 2) + 2);       //Right child is found at (index * 2) + 2
}

int quicksort(int data[], unsigned int n) {     
    unsigned int pivot_index;       //Maintains pivots location
    int n1, n2, swaps;              //n1 is number of elements before pivot
                                    //n2 is number of elements after pivot
    swaps = 0;                      //Swap counter for number of swaps in sorting algorithm
   
    if (n > 1) {                    //Checks for subarray being greater than 1, else nothing to sort
        swaps += partition(data, n, pivot_index);   //partitions array into sub arrays to be sorted
        
        n1 = pivot_index;           //sets n1 to pivot_index value so sorting wont walk off end of sub array
        n2 = n - n1 - 1;            //sets n2 to be 1 less than n - n1 so sorting wont walk off end of sub array
        
        swaps += quicksort(data, n1);   //recursively calls quicksort on sub arrays of length n1 and n2
        swaps += quicksort((data + pivot_index + 1), n2);   //uses pointer arithmetic to pass subarray
    }
    return swaps;       //return swaps
}

int insertionsort(int data[], unsigned int n) {
    int swaps = 0;  //Counter to keep track of number of swaps
    int index;      //Stores data value being sorted 
    
    for(int i = 0; i < n; i++) {    //Loops through entirety of array
        index = data[i];            //Sets index to unsorted comparison value
        for(int j = (i - 1); j >= 0; j--) { //Loops through unsorted values in array
            if(data[j] > index) {   //If sorted value is larger than unsorted value
                data[j + 1] = data[j];  //move sorted value up one position in array
                swaps++;            //Increment swaps
                if(j == 0) {        //If at the front of the array
                    data[j] = index;//Set unsorted value to first array position
                    swaps++;        //Increment swaps
                }
            } else if (index >= data[j]) {  //If unsorted value is less than sorted value
                data[j + 1] = index;    //store index value into data[j+1]; index value is now sorted 
                swaps++;                //Increment swaps
                j = -1;                 //Exit loop
            }
        }
        //print(data, n, i);
    }
        
    return swaps;   //Return swaps
}

int partition(int data[], int n, unsigned int& pivot_index) {
    int pivot, swaps;       //Keep track of pivot location, counter for number of swaps
    int too_big_index, too_small_index; //too_big_index is cursor moving from front to rear looking for values larger than pivot
                            //too_small_index is cursor moving from rear to front looking for values smaller than pivot
    swaps = 0;              //Swaps is set to zero
    
    pivot = data[0];        //Pivot is the first array value
    too_big_index = 1;      //too_big_index always starts as value after pivot
    too_small_index = n - 1;//too_small_index always starts at end of array
    
    while (too_big_index < too_small_index) {   //while too_big_index and too_small_index have not crossed index positions
        if(data[too_small_index] > pivot) {     //If value at too_small_index is larger than pivot, decrement too_small_index
            too_small_index--;
        }else if(data[too_big_index] < pivot) { //If value at too_big_index is smaller than pivot, increment too_big_index
            too_big_index++;
        } 
        
        if((data[too_big_index] > pivot) && (data[too_small_index] < pivot)) {  //If value at too_small_index is larger than pivot and
            swap(data[too_big_index], data[too_small_index]);       //value at too_big_index is larger than pivot, swap values
            swaps++;                            //Increment swaps
        }
    }
    if (pivot >= data[too_small_index]) {           //Ensures pivot value is not incorrectly being
        pivot_index = too_small_index;              //moved in front of values it is smaller than.
        data[0] = data[too_small_index];            //Pivot value is moved to its correct location in the
        data[too_small_index] = pivot;              //array. Increment swaps
        swaps++;
    } else {
        pivot_index = 0;                            //Otherwise pivot_index value is already in correct location
    }
    
    return swaps;                                   //return swaps
}

//Used for debugging of quicksort
void print(int data[], int n, int i) {
    cout << "Array at i = " << i << ": ";   //Prints array in set notation as it stands
    cout << "{";                            //during that iteration (i) of sorting algorithm
    for (int k = 0; k < n; k++) {
        cout << data[k] << ", ";
    }
    cout << "}" << endl;
}

