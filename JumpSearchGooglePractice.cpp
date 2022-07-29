#include <iostream>

using namespace std;

// Jump search is a search algorithm that finds the position of a target value within a sorted array(nondecreasing)
int jumpSearch(int inputArray[], int size, int target) {
	int step = sqrt(size); // Optimal block size to be jumped is sqrt(n)
	int prev = 0;

	// Find the block where the target value should be
	while (inputArray[min(step, size) - 1] < target) {
		prev = step;
		step += sqrt(size);

		// If we have reached the end of the array, the target value is not in the array
		if (prev >= size) {
			return -1;
		}
	}

	// Perform a linear search for the target value starting from prev
	while (inputArray[prev] < target) {
		prev++;

		// If we reach either the next block or the end of the array, the target value is not in the array
		if (prev == min(step, size)) {
			return -1;
		}
	}

	// Return prev if the target value is present at inputArray[prev] and return -1 if it is not in the array
	if (inputArray[prev] == target) {
		return prev;
	} else {
		return -1;
	}
}

int main() {
	int testArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	int sizeOfTestArray = sizeof(testArray) / sizeof(testArray[0]);

	int testTarget = 8;
	int searchResult = jumpSearch(testArray, sizeOfTestArray, testTarget);

	if (searchResult == -1) {
		cout << "The target value is not in the array." << endl;
	} else {
		cout << "The target value is at index " << searchResult << "." << endl;
	}

	return 0;
}