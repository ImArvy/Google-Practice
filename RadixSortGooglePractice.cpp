#include <iostream>

using namespace std;

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
void countSort(int inputArray[], int size, int exp) {
    int* countArray = new int[10] {0};
    int* outputArray = new int[size] {0};

    // Get the count of each value in inputArray[0...size - 1]
    for (int i = 0; i < size; i++) {
        countArray[(inputArray[i] / exp) % 10]++;
    }

    // Change countArray[i] so that countArray[i] now contains the position of this digit in outputArray[0...size - 1]
    for (int i = 1; i < 10; i++) {
        countArray[i] += countArray[i - 1];
    }

    // Stable implementation of building outputArray[0...size - 1]
    for (int i = size - 1; i >= 0; i--) {
        outputArray[countArray[(inputArray[i] / exp) % 10] - 1] = inputArray[i];
        countArray[(inputArray[i] / exp) % 10]--;
    }

    // Copy outputArray[0...size - 1] to inputArray[0...size - 1] so that inputArray[0...size - 1] is now sorted
    for (int i = 0; i < size; i++) {
        inputArray[i] = outputArray[i];
    }

    // Deallocate memory for the temporary count and output arrays
    delete[] countArray;
    delete[] outputArray;
}

void radixSort(int inputArray[], int size) {
    // Find the max value to know the number of digits
    int max = findMax(inputArray, size); 

    // Do counting sort for every digit where exp is 10 ^ i and i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(inputArray, size, exp);
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

    radixSort(testArray, sizeOfTestArray);

    cout << "Sorted Array: ";
    printArray(testArray, sizeOfTestArray);

    return 0;
}