/*
 * Title: powers.cpp
 * Abstract: This program outputs the result of 2 to the power of a given user
 *          positive integer
 * Author: Ivan Alejandre
 * ID: 8889
 * Date: 01/20/2020
 * */

#include <iostream>

using namespace std;

int power(int exponent);

int main() {
    int exponent;

    cout << "Enter any positive number: ";
    cin >> exponent;

    cout << "2 to the power of " << exponent << " is " << power(exponent) << "." << endl;

    return 0;
}

int power(int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return power(exponent - 1) * 2;
    }
}
