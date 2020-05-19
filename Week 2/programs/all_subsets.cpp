/*
 * Title: all_subsets.cpp
 * Abstract: This program outputs the power set of any given set given by a user
 * Author: Ivan Alejandre
 * ID: 8889
 * Date: 01/20/2020
 * */

#include <iostream>
#include <array>
#include <math.h>

using namespace std;

void printSets(int length, int total, char* array);

int main() {
    char * letters;
    int length;

    // ask user for information
    cout << "Number of input characters: ";
    cin >> length;
    letters = new char [length];

    cout << "Enter " << length << " characters: ";
    cin >> letters;

    cout << endl << "===== All Subsets =====" << endl;

    // find the power set. pass in the length of the letters array, the total
    // amount of sets, and the array itself
    int totalSubsets = pow(2, length);
    printSets(length, totalSubsets, letters);

    return 0;
}

void printSets(int length, int total, char* array) {
    // count from 0 to the total amount of subsets
    for (int i = 0; i < total; i++) {
        cout << "{ ";
        // bitshift the inner counter and perform bitwise AND with outer loop iterator
        for (int j = 0; j < length; j++) {
            if (( i & ( 1 << j)) > 0) {
                cout << array[j] << " ";
            }
        }
        cout << "}" << endl;
    }
}
