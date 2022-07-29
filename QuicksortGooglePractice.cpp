#include <iostream>

using namespace std;

// Swaps two elements
void swap(int *numOne, int *numTwo) {
    int temp = *numOne;
    *numOne = *numTwo;
    *numTwo = temp;
}

// Partitions a subarray using the last element as a pivot
int partition(int inputArray[], int left, int right) {
    int pivot = inputArray[right]; // Initialize pivot index
    int i = left - 1; // Initialize index of smaller elements which indicates the correct position of the pivot found so far

    for (int j = left; j <= right - 1; j++) {
        if (inputArray[j] < pivot) { // If the current element is smaller than the pivot
            i++; // Increment the index of the smaller element
            swap(&inputArray[i], &inputArray[j]); // Swap inputArray[i] and inputArray[j]
        }
    }
    swap(&inputArray[i + 1], &inputArray[right]);

    return i + 1;
}

// Sorts a sub array by quicksort
void quickSort(int inputArray[], int left, int right) {
    if (left < right) {
        int partitionIdx = partition(inputArray, left, right); // The partitioning index, inputArray[pivot] is now in the correct position
        
        quickSort(inputArray, left, partitionIdx - 1); // Perform quickSort on elements before the partitioning index 
        quickSort(inputArray, partitionIdx + 1, right); // Perform quickSort on elements after the partitioning index 
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

    quickSort(testArray, 0, sizeOfTestArray - 1);

    cout << "Sorted Array: ";
    printArray(testArray, sizeOfTestArray);

    return 0;
}