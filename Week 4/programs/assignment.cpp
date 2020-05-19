/*
 * Title: assignment.cpp
 * Abstract: Implements the assignment problem algorithm
 * Author: Ivan Alejandre
 * ID: 8889
 * Date: 2/4/2020
 * */

#include <iostream>
#include <algorithm>

using namespace std;

void printPermutation(int* permutation, int jobTotal, int cost);

int main () {
    int **jobWeights;
    int *permutation, *costPermutation;
    int jobTotal,
        cost = 0, column = 0, currentCost = 0, k = 1;

    // grab input from user
    cout << "Enter number of jobs: ";
    cin >> jobTotal;
    cout << "Enter assignment costs of " << jobTotal << " persons:" << endl;

    // create our dynamic arrays
    jobWeights = new int * [jobTotal];
    permutation = new int [jobTotal];
    costPermutation = new int [jobTotal];
    for (int i = 0; i < jobTotal; i++) {
        jobWeights[i] = new int [jobTotal];
        permutation[i] = i + 1; // seeds the permutation array
    }

    // continue with input by saving each line input into an 2d array
    for (int i = 0; i < jobTotal; i++) {
        cout << "Person " << i + 1 << ": ";
        for (int j = 0; j < jobTotal; j++) {
            cin >> jobWeights[i][j];
        }
    }

    // find initial cost of first permutation set from above
    for (int i = 0; i < jobTotal; i++) {
        column = permutation[i] - 1;
        cost = cost + jobWeights[i][column];
    }
    copy(permutation, permutation+jobTotal, costPermutation);

    // before updating values, output to screen first permutation
    cout << endl << "Permutation " << k << ": <";
    printPermutation(permutation, jobTotal, cost);
    k++;

    while(next_permutation(permutation, permutation+jobTotal)) {
        for (int i = 0; i < jobTotal; i++) {
            column = permutation[i] - 1;
            currentCost += jobWeights[i][column];
        }

        // before updating values, output to screen where we're at
        cout << "Permutation " << k << ": <";
        printPermutation(permutation, jobTotal, currentCost);

        if (currentCost < cost) {
            cost = currentCost;
            copy(permutation, permutation+jobTotal, costPermutation);
        }
        currentCost = 0;
        k++;
    }

    cout << endl << "Solution: <";
    printPermutation(permutation, jobTotal, cost);

    return 0;
}

void printPermutation(int* permutation, int jobTotal, int cost) {
    for (int i = 0; i < jobTotal; i++) {
        if (i == jobTotal - 1) {
            cout << permutation[i];
        } else {
            cout << permutation[i] << ", ";
        }
    }
    cout << "> => total cost: " << cost << endl;
}