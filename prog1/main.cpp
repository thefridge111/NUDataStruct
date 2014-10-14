// main.cpp

#include <iostream>
#include "../array.h"

using namespace std;

int main() {
    cout << "Creating a character array of size 5." << endl;

    myArray newArr(5);
    newArr.SetArray('W', 0);
    newArr.SetArray('i', 1);
    newArr.SetArray('l', 2);
    newArr.SetArray('l', 3);
    newArr.SetArray('!', 4);

    cout << "Array contents: " << newArr.GetArray(0) <<
            newArr.GetArray(1) << newArr.GetArray(2) <<
            newArr.GetArray(3) << newArr.GetArray(4) << endl;

    return 0;
}

