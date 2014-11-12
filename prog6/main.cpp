/* 
 * File:   main.cpp
 * Author: Will
 *
 * Created on November 11, 2014, 10:32 AM
 */

#include <cstdlib>
#include "../BinarySearch.h"
#include <iostream>

using namespace std;

int main() {
 int z1[8] = { -22, 4, 51, 52, 330, 401, 403, 1097};
 int z2[3] = { 7, -5, 0};
 try {
 cout << search(z1, 8, 404, true) << endl; // This should print -1
 cout << search(z1, 8, 51, true) << endl; // This should print 2
 cout << search(z2, 3, 404, false) << endl; // This should print -1
 cout << search(z2, 3, 7, false) << endl; // This should print 0 
 } catch (...) {
     cout << "ERROR!" << endl;
 }
 return 0;
}

