/* 
 * File:   BinarySearch.cpp
 * Author: Will
 *
 * Created on November 11, 2014, 10:07 AM
 */
#include "BinarySearch.h"
#include <iostream>
#include <cstdlib>

int search(int A[], unsigned int L, int target, bool sorted) {
//int A[] is the array to be searched
//int L is the size of the array
//int target is the integer to be searched for
//bool sorted is if array is sorted
    unsigned int first, last, middle, tempMid;
    
    if (L > 0) {;
        middle = (L / 2) + 1;
        first = 0;
        last = L - 1;
        
        if (!sorted) {
            for (unsigned int i = 0; i <= L; i++) {
                if (A[i] == target) {
                    return i;
                }
            }
            return -1;
        } else {
            if (target == A[middle]) {
                return A[middle];
            }
            else {
                tempMid = middle;
                for (unsigned int j = 0; j < middle; j++) {
                    if (tempMid < 0 || tempMid >= L) {
                        throw "Invalid index value. Index exceed size.";
                    } else if(target < A[tempMid]) {
                        last = tempMid;
                        if ((last - first) == 1) {
                            tempMid--;
                        } else {
                        tempMid = (first + ((last - first) / 2));
                        }
                    } else if ( target > A[tempMid]) {
                        first = tempMid;
                        if ((last - first) == 1) {
                            tempMid++;
                        } else {
                        tempMid = (first + ((last - first) / 2));
                        }
                    } else if (target == A[tempMid]) {
                        return tempMid;
                    } 
                }
                return -1;
            } 
        }
    }
}
