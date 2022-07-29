// LinearSearchGooglePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Linear search is a search algorithm that finds the position of a target value within an array
int linearSearch(int inputArray[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (target == inputArray[i]) {
			return i;
		}
	}

	return -1;
}

int main() {
	int testArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	int sizeOfTestArray = sizeof(testArray) / sizeof(testArray[0]);

	int testTarget = 8;
	int searchResult = linearSearch(testArray, sizeOfTestArray, testTarget);

	if (searchResult == -1) {
		cout << "The target value is not in the array." << endl;
	} else {
		cout << "The target value is at index " << searchResult << "." << endl;
	}

	return 0;
}