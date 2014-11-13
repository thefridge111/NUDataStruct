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
        middle = (L / 2) + 1;       //Defines an initial 'middle' of the array
        first = 0;                  //Holds the first value of array/array subset 
        last = L - 1;               //Holds the last value of array/array subset
        
        if (!sorted) {              //Checks if array is sorted
            for (unsigned int i = 0; i <= L; i++) { //Begin serial search
                if (A[i] == target) {               //Check if array value is target
                    return i;                       //Returns index value if found
                }
            }
            return -1;              //Return -1 if not found              
        } else {
            if (target == A[middle]) {      //Checks if middle is target value
                return middle;              //Returns middle index value
            }
            else {
                tempMid = middle;           //Sets a middle value that will change
                for (unsigned int j = 0; j < middle; j++) { 
                    if (tempMid < 0 || tempMid >= L) {  //Checks if walked off end of array
                        throw "Invalid index value. Index exceeds size.";
                    } else if(target < A[tempMid]) {    //Checks if target is less than middle
                        last = tempMid;                 //Moves end of array subset to middle value
                        if ((last - first) == 1) {      //If difference is 1 then decrement middle value
                            tempMid--;
                        } else {
                        tempMid = (first + ((last - first) / 2)); //Moves middle value halfway between first and last values
                        }
                    } else if ( target > A[tempMid]) {  //Checks if target is greater than middle
                        first = tempMid;                //Moves beginning of array subset to middle value
                        if ((last - first) == 1) {      //If difference is 1 then increment middle value
                            tempMid++;                  
                        } else {
                        tempMid = (first + ((last - first) / 2)); //Moves middle value halfway between first and last values
                        }
                    } else if (target == A[tempMid]) {  //Check if target is at middle index value 
                        return tempMid;
                    } 
                }
                return -1;          //If value is not in array
            } 
        }
    }
}
