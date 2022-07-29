#include <iostream>

using namespace std;

// Binary search is a search algorithm that finds the position of a target value within a sorted array(nondecreasing)
int binarySearch(int inputArray[], int target, int left, int right) {
    if (right >= left) {
        int middle = left + (right - left) / 2;

        if (target == inputArray[middle]) { // If the target value is equal to the element at the middle index
            return middle; // Return the middle index
        } else if (target < inputArray[middle]) { // If the target value is less than the element at the middle index
            return binarySearch(inputArray, target, left, middle - 1); // Recursively perform binary search in the left sub array
        } else { // If the target value is greater than the element at the middle index
            return binarySearch(inputArray, target, middle + 1, right); // Recursively perform binary search in the right sub array
        }
    } else {
        return -1; // Target value is not in the array
    }
}

// Exponential search is a search algorithm that finds the position of a target value within a sorted array(nondecreasing)
int exponentialSearch(int inputArray[], int size, int target) {
    // Return 0 if target value is at inputArray[0]
    if (target == inputArray[0]) {
        return 0;
    } else {
        // Find range to perform binary search in by doubling index i repeatedly
        int i = 1;
        while (i < size && target >= inputArray[i]) {
            i *= 2;
        }

        // Perform binary search in this found range
        // Once we find an index i after repeated doubling of it, we know that the element must be present between i / 2 and i 
        // Why i / 2? because we could not find a greater value in the previous iteration
        return binarySearch(inputArray, target, i / 2, min(i, size - 1)); 
    }
}

int main() {
    int testArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int sizeOfTestArray = sizeof(testArray) / sizeof(testArray[0]);

    int testTarget = 8;
    int searchResult = exponentialSearch(testArray, sizeOfTestArray, testTarget);

    if (searchResult == -1) {
        cout << "The target value is not in the array." << endl;
    } else {
        cout << "The target value is at index " << searchResult << "." << endl;
    }

    return 0;
}