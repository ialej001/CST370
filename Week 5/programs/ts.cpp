/* Title: ts.cpp
 * Abstract: Implementation of topological sorting based on the source-removal
 * algorithm
 * ID: 8889
 * Author: Ivan Alejandre
 * Date: 2/10/2020
 * */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string fileName;
    ifstream file;
    int dataSize, **matrix, *connections, *visited;

    // ask user for file name
    cout << "Enter input file name: ";
    cin >> fileName;

    file.open(fileName.c_str());

    // read file contents: first line is max num of array, all other are contents
    // if file doesn't exist, end program. this program assumes the text file
    // contains all integers
    if (file.is_open()) {
        file >> dataSize;
        matrix = new int * [dataSize];
        connections = new int [dataSize];
        visited = new int [dataSize];

        // fill 2D array with remaining data
        for (int i = 0; i < dataSize; i++) {
            matrix[i] = new int[dataSize];
            connections[i] = 0;
            visited[i] = 0;
            for (int j = 0; j < dataSize; j++)
                file >> matrix[i][j];
        }
    }
    else
    {
        cout << endl << "Unable to open file! (\"" << fileName << "\")";
        return 0;
    }

    // create our connections list
    for (int i = 0; i < dataSize; i++) {
        for (int j = 0; j < dataSize; j++)
            connections[i] = connections[i] + matrix[j][i];
    }

    cout << "Topological sort: ";

    for (int i = 0; i < dataSize; i++) {
        for (int j = 0; j < dataSize; j++) {
            if (connections[j] == 0 && visited[j] == 0) {
                if (i + 1 == dataSize)     // print
                    cout << j;
                else
                    cout << j << " --> ";

                visited[j] = 1;         // mark as visited

                for (int k = 0; k < dataSize; k++) {
                    if(matrix[j][k] == 1) {
                        matrix[j][k] = 0;   // mark as removed
                        connections[k]--;   // remove that connection
                    }
                }
                break; // move to next row
            }
        }
    }

    // clean up
    for (int i = 0; i < dataSize; i++)
        delete[] matrix[i];
    delete[] matrix, connections, visited;

    return 0;
}