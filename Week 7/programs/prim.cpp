/* Title: prim.cpp
 * Abstract: Obtains a list to construct a minimal spanning tree using Prim's algorithm.
 * ID: 8889
 * Author: Ivan Alejandre
 * Date: 2/24/2020
 * */

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

#define INF 99999999

int main() {
    string fileName;
    ifstream file;
    int vertices, edges, **matrix, edgesVisited, cost, nodeToAdd, startVert, x;
    int * visited;

    // ask user for file name
    cout << "Enter input file name: ";
    cin >> fileName;

    file.open(fileName.c_str());

    // read file contents: first line is max num of array, all other are contents
    // if file doesn't exist, end program. this program assumes the text file
    // contains all integers
    if (file.is_open()) {
        file >> vertices;
        file >> edges;
        matrix = new int * [vertices+1];
        visited = new int [vertices+1];

        // fill 2D array with 0 int data
        // we don't use the 0 index of either array.
        for (int i = 1; i <= vertices; i++) {
            matrix[i] = new int[vertices+1];
            visited[i] = false;
            for (int j = 1; j <= vertices; j++)
                matrix[i][j] = 0;
        }

        int i, j, w;
        while (file >> i >> j >> w) {
            matrix[i][j] = w; // map intended direction
            matrix[j][i] = w; // map opposite direction
        }
    }
    else
    {
        cout << endl << "Unable to open file! (\"" << fileName << "\")";
        return 0;
    }

    cout << "Enter the first vertex to start: ";
    cin >> startVert;
    visited[startVert] = true;  // start here, mark as visited

    while (edgesVisited < vertices-1) { // prim algo solution has V - 1 edges
        cost = INF;
        x = 0;
        nodeToAdd = 0;
        for (int i = 1; i <= vertices; i++) {
            if (visited[i]) {   // if we've been here, check adjacent nodes
                for (int j = 1; j <= vertices; j++) {   // iterate all nodes not visited
                    if (!visited[j] && matrix[i][j]) {  // unvisited adjacent node w/ weight
                        if (matrix[i][j] < cost) {
                            cost = matrix[i][j];
                            x = i;
                            nodeToAdd = j;
                        }
                    }
                }
            }
        }

        cout << "(" << edgesVisited+1 << ") New Edge: " << x << "," << nodeToAdd;
        cout << " - cost " << cost << endl;

        visited[nodeToAdd] = true;
        edgesVisited++;
    }

    // clean up
    for (int i = 1; i <= vertices; i++)
        delete[] matrix[i];
    delete[] matrix, visited;
}