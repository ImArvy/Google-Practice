#include <iostream>

using namespace std;

int findMin(int inputArray[], int size) {
    int min = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (inputArray[i] < min) {
            min = inputArray[i];
        }
    }

    return min;
}

int findMax(int inputArray[], int size) {
    int max = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (inputArray[i] > max) {
            max = inputArray[i];
        }
    }

    return max;
}

// Sorts a sub array by count sort, this version is stable and works with negative numbers
void countSort(int inputArray[], int size) {
    int min = findMin(inputArray, size);
    int max = findMax(inputArray, size);
    int range = max - min + 1;
    
    int* countArray = new int[range] {0};
    int* outputArray = new int[size] {0};

    // Get the count of each value in inputArray[0...size - 1]
    for (int i = 0; i < size; i++) {
        countArray[inputArray[i] - min]++;
    }

    // Add the count from countArray[i - 1] to countArray[i] for countArray[1...range - 1]
    for (int i = 1; i < range; i++) {
        countArray[i] += countArray[i - 1];
    }

    // Stable implementation of building outputArray[0...size - 1]
    for (int i = size - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i] - min] - 1] = inputArray[i];
        countArray[inputArray[i] - min]--;
    }

    // Copy outputArray[0...size - 1] to inputArray[0...size - 1] so that inputArray[0...size - 1] is now sorted
    for (int i = 0; i < size; i++) {
        inputArray[i] = outputArray[i];
    }

    // Deallocate memory for the temporary count and output arrays
    delete[] countArray;
    delete[] outputArray;
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

    countSort(testArray, sizeOfTestArray);

    cout << "Sorted Array: ";
    printArray(testArray, sizeOfTestArray);

    return 0;
}