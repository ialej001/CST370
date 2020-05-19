/*
 * Title: hw1_1.cpp
 * Abstract: This program outputs the minimum distance of two numbers contained
 *          in a dynamic array
 * Author: Ivan Alejandre
 * ID: 8889
 * Date: 01/07/2020
 * */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string fileName;
    ifstream file;
    int dataSize, distance = 0x7fffffff, // distance is set to max int value
     number1, number2, newDistance;
    int * numbers;

    // ask user for file name
    cout << "Enter input file name: ";
    cin >> fileName;
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

    // go through array, determine smallest distance. outer loop determines
    // first number and inner loop is the second number. we ignore duplicates
    // by filtering 0 distance values
    for (int i = 0; i < dataSize; i++)
    {
        for (int j = i+1; j < dataSize; j++)
        {
            newDistance = abs(numbers[i] - numbers[j]);
            if (newDistance < distance && newDistance > 0)
            {
                number1 = numbers[i];
                number2 = numbers[j];
                distance = newDistance;
            }
        }
    }

    // display our results
    cout << endl << "Output:";
    cout << endl << "    Min distance: " << distance << endl;
    cout << "    Two numbers for min distance: " << number1 << " and ";
    cout << number2 << endl;

    // close file and delete dynamic array
    file.close();
    delete[] numbers;

    return 0;
}