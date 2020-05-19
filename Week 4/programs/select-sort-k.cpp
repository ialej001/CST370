/*
 * Title: select-sort-k.cpp
 * Abstract: Sorts an array of size n from 0 to element k where k <= n
 * Author: Ivan Alejandre
 * ID: 8889
 * Date: 2/3/2020
 * */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    string fileName;
    ifstream file;
    int dataSize, k, min, temp;
    int * numbers;

    // ask user for file name and size of k
    cout << "Enter input file name: ";
    cin >> fileName;
    cout << "Enter the value k: ";
    cin >> k;
    file.open(fileName.c_str());

    // read file contents: first line is max num of array, all other are contents
    // if file doesn't exist, end program. this program assumes the text file
    // contains all integers
    if (file.is_open()) {
        // grab array size then declare/init integer array
        file >> dataSize;
        numbers = new int [dataSize];

        // fill array with remaining data
        for (int i = 0; i < dataSize; i++) {
            file >> numbers[i];
        }
    }
    else
    {
        cout << endl << "Unable to open file! (\"" << fileName << "\")";
        return 0;
    }

    // it should be assumed that the user knows the max array, this is a safeguard
    if (k > dataSize)
    {
        k = dataSize;
    }
    // selection sort where k is the maximum of elements we're allowed to move to
    // the right (from 0)
    for (int i = 0; i < k; i++)
    {
        min = i;
        for (int j = i + 1; j < dataSize; j++)
        {
            if (numbers[j] < numbers[min])
            {
                min = j;
            }
            temp = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = temp;
        }
    }

    // display our results
    cout << endl << "Output: ";
    for (int i = 0; i < k; i++)
    {
        if (i + 1 == k)
        {
            cout << numbers[i];
        } else {
            cout << numbers[i] << ", ";
        }
    }

    // close file and delete dynamic array
    file.close();
    delete[] numbers;

    return 0;
}