


#include "sorting.h"
#include <iostream>

int heapsort(int data[], unsigned int n) {  
    int unsorted, swaps;
    swaps = 0;
    
    make_heap(data, n);
    
    unsorted = n;
    
    while(unsorted > 1) {
        unsorted--;
        swap(data[0], data[unsorted]);
        swaps++;
        swaps += reheapify_down(data, unsorted);
    }
    
    return swaps;
}

void make_heap(int data[], int n) {
    int k, temp;
    
    for (int i = 1; i < n; i++) {
        k = i;
        while ((data[k] > data[parent(k)]) && (k > 0)) {
            temp = data[k];
            data[k] = data[parent(k)];
            data[parent(k)] = temp;
            k = parent(k);
        }
    }
}

int parent(int k) {
    return ((k - 1) / 2);
}

void swap(int& data, int& unsorted){
    int temp;
    
    temp = data;
    data = unsorted;
    unsorted = temp;
}

int reheapify_down(int data[], int n) {
    int current, temp, swaps = 0;
    int big_child_index, rightChild, leftChild;
    bool heap_ok;
    
    current = 0;
    heap_ok = false;
    
    while ((!heap_ok) && (((current * 2) + 1) < n)) {
        rightChild = right_child(current);
        leftChild = left_child(current);
        
        if((leftChild < n) && (rightChild < n)) {
            if (data[leftChild] > data[rightChild]) {
                big_child_index = leftChild;
            } else {
                big_child_index = rightChild;
            }
        } else {
            big_child_index = leftChild;
        }
        
        if (data[current] < data[big_child_index]) {
            swap(data[current], data[big_child_index]);
            swaps++;
            current = big_child_index;
        } else {
            heap_ok = true;
        }
    }
    return swaps;
}

int left_child(int index) {
    return ((index * 2) + 1);
}

int right_child(int index) {
    return ((index * 2) + 2);
}

int quicksort(int data[], unsigned int n) {     
    unsigned int pivot_index;
    int n1, n2, swaps;
    
    swaps = 0;
   
    if (n > 1) {
        swaps += partition(data, n, pivot_index);
        
        n1 = pivot_index;
        n2 = n - n1 - 1;
        
        swaps += quicksort(data, n1);
        swaps += quicksort((data + pivot_index + 1), n2);
    }
    return swaps;  
}

int insertionsort(int data[], unsigned int n) {
    int swaps = 0;
    int index;
    
    for(int i = 0; i < n; i++) {
        index = data[i];
        for(int j = (i - 1); j >= 0; j--) {
            if(data[j] > index) {
                data[j + 1] = data[j];
                swaps++;
                if(j == 0) {
                    data[j] = index;
                    swaps++;
                }
            } else if (index >= data[j]) {
                data[j + 1] = index;
                swaps++;
                j = -1;
            }
        }
        //print(data, n, i);
    }
        
    return swaps;
}

int partition(int data[], int n, unsigned int& pivot_index) {
    int pivot, swaps;
    int too_big_index, too_small_index;
    swaps = 0;
    
    pivot = data[0];
    too_big_index = 1;
    too_small_index = n - 1;
    
    while (too_big_index < too_small_index) {
        if(data[too_small_index] > pivot) {
            too_small_index--;
        }else if(data[too_big_index] < pivot) {
            too_big_index++;
        } 
        
        if((data[too_big_index] > pivot) && (data[too_small_index] < pivot)) {
            swap(data[too_big_index], data[too_small_index]);
            swaps++;
        }
    }
    if (pivot >= data[too_small_index]) {           //Ensures pivot value is not incorrectly being
        pivot_index = too_small_index;              //moved in front of values it is smaller than.
        data[0] = data[too_small_index];
        data[too_small_index] = pivot;
        swaps++;
    } else {
        pivot_index = 0;
    }
    
    return swaps;
}

void print(int data[], int n, int i) {
    cout << "Array at i = " << i << ": ";
    cout << "{";
    for (int k = 0; k < n; k++) {
        cout << data[k] << ", ";
    }
    cout << "}" << endl;
}

