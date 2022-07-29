#include <iostream>

using namespace std;

void merge(int inputArray[], int left, int middle, int right) {
	// Size of left and right sub arrays
	int leftSubArraySize = middle - left + 1;
	int rightSubArraySize = right - middle;

	// Initialize temporary sub arrays
	int *leftSubArray = new int[leftSubArraySize];
	int *rightSubArray = new int[rightSubArraySize];

	// Copy inputArray[left...mid - 1] to leftSubArray  
	for (int i = 0; i < leftSubArraySize; i++) {
		leftSubArray[i] = inputArray[left + i];
	}
	 // Copy inputArray[mid...right - 1] to rightSubArray
	for (int j = 0; j < rightSubArraySize; j++) {
		rightSubArray[j] = inputArray[middle + 1 + j];
	}

	int leftSubArrayIdx = 0; // Starting index of left sub array
	int rightSubArrayIdx = 0; // Starting index of right sub array
	int mergedArrayIdx = left; // Starting index of merged array 

	// While the indices of the left right sub arrays are in range of their respective sub arrays
	while (leftSubArrayIdx < leftSubArraySize && rightSubArrayIdx < rightSubArraySize) {
		// Compare the elements of leftSubArray and rightSubArray
		if (leftSubArray[leftSubArrayIdx] <= rightSubArray[rightSubArrayIdx]) { 
			inputArray[mergedArrayIdx] = leftSubArray[leftSubArrayIdx]; // The smaller of them is added to a new array
			leftSubArrayIdx++; // The index of the smaller element is incremented to point to its immediate successor in the array it was copied from
		} else {
			inputArray[mergedArrayIdx] = rightSubArray[rightSubArrayIdx];
			rightSubArrayIdx++;
		}

		mergedArrayIdx++; // Increment the index of the merged array
	}

	// Copy any remaining elements of leftSubArray to inputArray
	while (leftSubArrayIdx < leftSubArraySize) {
		inputArray[mergedArrayIdx] = leftSubArray[leftSubArrayIdx];
		leftSubArrayIdx++;
		mergedArrayIdx++;
	}

	// Copy any remaining elements of rightSubArray to inputArray
	while (rightSubArrayIdx < rightSubArraySize) {
		inputArray[mergedArrayIdx] = rightSubArray[rightSubArrayIdx];
		rightSubArrayIdx++;
		mergedArrayIdx++;
	}

	// Deallocate memory for the temporary sub arrays
	delete[] leftSubArray;
	delete[] rightSubArray;
}

void mergeSort(int inputArray[], int left, int right) {
	if (left >= right) {
		return;
	}

	int middle = left + (right - left) / 2;

	mergeSort(inputArray, left, middle); // Perform mergeSort on left sub arrays recursively
	mergeSort(inputArray, middle + 1, right); // Perform mergeSort on right sub arrays recursively
	merge(inputArray, left, middle, right); // Merge the left and right sub arrays recursively
}

void printArray(int inputArray[], int sizeOfInputArray) {
	for (int i = 0; i < sizeOfInputArray; i++) {
		cout << inputArray[i] << ' ';
	}

	cout << endl;
}

int main() {
	int testArray[] = { 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int sizeOfTestArray = sizeof(testArray) / sizeof(testArray[0]);
	
	cout << "Test Array: ";
	printArray(testArray, sizeOfTestArray);

	mergeSort(testArray, 0, sizeOfTestArray - 1);

	cout << "Sorted Array: ";
	printArray(testArray, sizeOfTestArray);

	return 0;
}