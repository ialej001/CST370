/*
 * Title: BFS.cpp
 * Abstract: Implements Breadth-First Search algorithm
 * Author: Ivan Alejandre
 * ID: 8889
 * Date: 2/3/2020
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main () {
    string fileName;
    ifstream file;
    int dataSize, startVert, count, s;
    int** matrix;
    bool* visited;
    int* order;
    queue<int> queue;

    // ask user for file name
    cout << "Enter input file name: ";
    cin >> fileName;
    cout << "Enter a start vertex: ";
    cin >> startVert;

    file.open(fileName.c_str());

    // read file contents: first line is max num of array, all other are contents
    // if file doesn't exist, end program. this program assumes the text file
    // contains all integers
    if (file.is_open()) {
        file >> dataSize;
        matrix = new int * [dataSize];
        order = new int [dataSize];
        visited = new bool [dataSize];
        for (int i = 0; i < dataSize; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < dataSize; i++) {
            matrix[i] = new int[dataSize];
        }

        // fill 2D array with remaining data
        for (int i = 0; i < dataSize; i++) {
            for (int j = 0; j < dataSize; j++) {
                file >> matrix[i][j];
            }
        }
    }
    else
    {
        cout << endl << "Unable to open file! (\"" << fileName << "\")";
        return 0;
    }

    // BFS algorithm: starting at the user selected node, visit
    // all adjacent nodes before going deeper into the tree
    count = 0; // order in which the nodes are visited
    order[startVert] = count; // start with user inputted number
    visited[startVert] = true;
    queue.push(startVert);

    while(!queue.empty()) {
        s = queue.front();
        queue.pop();

        for (int i = 0; i < dataSize; i++) {
            if (matrix[s][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.push(i);
                count++;
                order[i] = count;
            }
        }
    }

    // display to console
    for (int i = 0; i < dataSize; i++) {
        if (i+1 == dataSize) {
            cout << order[i];
        } else {
            cout << order[i] << " -> ";
        }
    }

    // clean up
    for (int i = 0; i < dataSize; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}