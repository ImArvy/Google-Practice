#include <iostream>

using namespace std;

// Swaps two nodes
void swapNodes(int* nodeOne, int* nodeTwo) {
    int tempNode = *nodeOne;
    *nodeOne = *nodeTwo;
    *nodeTwo = tempNode;
}

// Heapify a subtree with node i as the root, where i is an index in inputArray[0...size - 1]
void heapify(int inputArray[], int size, int i) {
    int max = i; // Initialize max as the root
    int left = 2 * i + 1; // Initialize left using formaula 2 * i + 1
    int right = 2 * i + 2; // Initialze right using formula 2 * i + 2

    // If the left child is larger than the root
    if (left < size && inputArray[left] > inputArray[max]) {
        max = left;
    }

    // If the right child is larger than the max so far
    if (right < size && inputArray[right] > inputArray[max]) {
        max = right;
    }

    // If max is not the root after the two previous checks
    if (max != i) {
        swapNodes(&inputArray[max], &inputArray[i]); // Swap the root with max
        heapify(inputArray, size, max); // Recursively heapify the subtree where the swap took place
    }
}

// Heap sort : build max heap, swap the current root with the last node, delete the root that was swapped, and heapify the newly reduced heap
void heapSort(int inputArray[], int size) {
    // Build max heap AKA rearrange array to satisfy parental dominance
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(inputArray, size, i);
    }

    // Remove each node in the heap one by one
    for (int i = size - 1; i > 0; i--) {
        swapNodes(&inputArray[0], &inputArray[i]); // Swap current root with the last node in the heap
        heapify(inputArray, i, 0); // Heapify the newly reduced heap, size decreases because i decreases
    }
}

// Prints an array
void printArray(int inputArray[], int size) {
    for (int i = 0; i < size; i++) {
        cout << inputArray[i] << ' ';
    }

    cout << endl;
}

int main() {
    int testArray[] = { 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int sizeOfTestArray = sizeof(testArray) / sizeof(testArray[0]);

    cout << "Test Array: ";
    printArray(testArray, sizeOfTestArray);

    heapSort(testArray, sizeOfTestArray);

    cout << "Sorted Array: ";
    printArray(testArray, sizeOfTestArray);

    return 0;
}