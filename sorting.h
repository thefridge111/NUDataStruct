/*Sorting project header:  
 * Heap sort
 * Insertion sort   
 * Quicksort 
 *
 * Written by Will Perry
 * IS228
 * December 2014
 */

#ifndef SORTING_H
#define	SORTING_H

#include <cstdlib>

using namespace std;

//data[] is the array being sorted
//n is the length of data[]
int heapsort(int data[], unsigned int n);       //Heap sort
int quicksort(int data[], unsigned int n);      //Quicksort
int insertionsort(int data[], unsigned int n);  //Insertion sort

//-----------Helper Functions---------------
//***General Helpers***
void swap(int& data, int& unsorted);            //Swaps values at two array positions
void print(int data[], int n, int i);           //Prints array data[] of n length at each i position in sorting process.
                                                //Used for debugging.
//***Heap sort***
int make_heap(int data[], int n);int parent(int k);    //Builds heap with largest values at the top
int reheapify_down(int data[], int n);          //Arranges array to have largest value at top again
bool is_parent(int current);                    //Checks if a array at current index has any children
int left_child(int index);                      //Finds left child index 
int right_child(int index);                     //Finds right child index
//***Quicksort***
int partition(int data[], int n, unsigned int& pivot_index);    //Partitions array into sub-arrays, sorts arrays and moves pivot values
                                                //into final index location

#endif	/* SORTING_H */

