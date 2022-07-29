#include <iostream>

using namespace std;

void insertionSort(int inputArray[], int size) {
	for (int i = 1; i < size; i++) {
		int key = inputArray[i];
		int j = i - 1;
		// Shift elements of inputArray that are greater than the key one position forward
		while (j >= 0 && inputArray[j] > key) {
			inputArray[j + 1] = inputArray[j];
			j--;
		}
		inputArray[j + 1] = key; // Place the key after the first element that is less than or equal to the key
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

    insertionSort(testArray, sizeOfTestArray);

    cout << "Sorted Array: ";
    printArray(testArray, sizeOfTestArray);

    return 0;
}