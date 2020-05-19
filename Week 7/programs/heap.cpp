/* Title: heap.cpp
 * Abstract: Small program that implements heap insertions, max value deletions,
 * and heap sort (decreasing order)
 * ID: 8889
 * Author: Ivan Alejandre
 * Date: 2/24/2020
 * */
#include <iostream>
#include <cmath>

using namespace std;

int* heapBottomUp(int *heap, int size);

bool heapCheck(int *heap, int size);

int* heapInsert(int *heap, int size, int newInsert);

int* heapDeleteMax(int *heap, int size);

int* heapSort(int *heap, int size);

void printHeap(int *heap, int size);

int main() {
    int size, *heap, choice, newInsert;
    bool execute = true;

    cout << "Input size: ";
    cin >> size;
    size++; // consider heap starts at 1, not 0
    heap = new int [size];
    cout << "Enter numbers: ";
    for (int i = 1; i < size; i++)
        cin >> heap[i];

    // pass array to heapCheck. if returned as false, reconstruct heap
    if (heapCheck(heap, size-1))
        cout << "This is a heap.\n";
    else {
        cout << "This is NOT a heap.\n";
        heap = heapBottomUp(heap, size);
        cout << "Heap constructed: ";
        printHeap(heap, size);
    }

    // enter program loop
    do {
        cout << "\nSelect an operation" << endl;
        cout << "\t1: Insert a number" << endl;
        cout << "\t2: Delete the max" << endl;
        cout << "\t3: Heapsort & Quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: // insert
                cout << "Enter a number: ";
                cin >> newInsert;
                heap = heapInsert(heap, size++, newInsert); //size is modified in main to track array size
                cout << "Updated heap: ";
                printHeap(heap, size);
                break;
            case 2: // delete
                heap = heapDeleteMax(heap, size--);
                cout << "Updated heap: ";
                printHeap(heap, size);
                break;
            case 3: // sort & quit
                heap = heapSort(heap, size);
                cout << "Heapsort: ";
                printHeap(heap, size);
                cout << "Bye!";
                execute = false;
                break;
            default:
                cout << "Not a valid choice, try again." << endl;
        }
    } while (execute);

    delete[] heap;

    return 0;
}

int* heapBottomUp(int *heap, int size) {
    int k, j, v;
    bool isHeap;
    for (int i = floor(size/2); i > 0; i--) {
        k = i;
        v = heap[k];
        isHeap = false;
        while (!isHeap && 2 * k <= size) {
            j = 2 * k;
            if (j < size) {
                if (heap[j] < heap[j + 1])
                    j++;
            }
            if (v >= heap[j])
                isHeap = true;
            else {
                heap[k] = heap[j];
                k = j;
                heap[k] = v;
            }
        }
    }

    return heap;
}

bool heapCheck(int *heap, int size) {
    int k, j, v;
    bool isHeap;
    for (int i = floor(size/2); i > 0; i--) {
        k = i;
        v = heap[k];
        isHeap = false;
        while (!isHeap && 2 * k <= size) {
            j = 2 * k;
            if (j < size) {
                if (heap[j] < heap[j + 1])
                    j++;
            }
            if (v >= heap[j])
                isHeap = true;
            else
                return false;   // same as heapBottomUp, with this key difference
        }
    }
    return true;
}

int* heapInsert(int *heap, int size, int newInsert) {
    size++; // in main function call, increment in argument does not pass into function as executed
    int *newHeap = new int [size];
    for (int i = 1; i < size; i++)
        newHeap[i] = heap[i];

    newHeap[size-1] = newInsert;
    newHeap = heapBottomUp(newHeap, size);
    return newHeap;
}

int* heapDeleteMax(int *heap, int size) {
    int temp;
    int *newHeap = new int [size];
    size--;
    temp = heap[1];
    heap[1] = heap[size];
    heap[size] = temp;
    for (int i = 1; i < size; i++)
        newHeap[i] = heap[i];

    newHeap = heapBottomUp(newHeap, size);
    return newHeap;
}

int* heapSort(int *heap, int size) {
    int *newHeap = new int [size];
    int temp, j = 1;
    for (int i = size-1; i > 0; i--) {
        temp = heap[1];
        heap[1] = heap[i];
        heap[i] = temp;
        newHeap[j] = temp;
        j++;
        heap = heapBottomUp(heap, i-1);
    }
    return newHeap;
}

void printHeap(int *heap, int size) {
    for (int i = 1; i < size; i++)
        cout << heap[i] << " ";
    cout << endl;
}