/* 
 * File:   sorting.h
 * Author: Will
 *
 * Created on December 2, 2014, 10:25 AM
 */

#ifndef SORTING_H
#define	SORTING_H

#include <cstdlib>

using namespace std;

int heapsort(int data[], unsigned int n);
int quicksort(int data[], unsigned int n);
int insertionsort(int data[], unsigned int n);

int partition(int data[], int n, unsigned int& pivot_index);
void make_heap(int data[], int n);
void swap(int& data, int& unsorted);
int reheapify_down(int data[], int n);
int parent(int k); 
bool is_parent(int current);
int left_child(int index);
int right_child(int index);

void print(int data[], int n, int i);
/*
    unsigned int pivot_index;
    int n1, n2, swaps;
*/


#endif	/* SORTING_H */

