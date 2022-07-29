// InterpolationSearchGooglePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Interpolation search is a search algorithm that finds the position of a target value within a sorted array(nondecreasing)
int interpolationSearch(int inputArray[], int target, int left, int right) {
    int pos;
    
    // If the target value is in range of the sorted array
    if (left <= right && target >= inputArray[left] && target <= inputArray[right]) {
        // Set the position using uniformm distribution
        pos = left + (target - inputArray[left]) * (right - left) / (inputArray[right] - inputArray[left]);

        if (target == inputArray[pos]) {
            return pos;
        } else if (target < inputArray[pos]) {
            return interpolationSearch(inputArray, target, left, pos - 1);
        } else if (target > inputArray[pos]) {
            return interpolationSearch(inputArray, target, pos + 1, right);
        }
    } else {
        return -1;
    }
}

int main() {
    int testArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int sizeOfTestArray = sizeof(testArray) / sizeof(testArray[0]);

    int testTarget = 8;
    int searchResult = interpolationSearch(testArray, testTarget, 0, sizeOfTestArray - 1);

    if (searchResult == -1) {
        cout << "The target value is not in the array." << endl;
    } else {
        cout << "The target value is at index " << searchResult << "." << endl;
    }

    return 0;
}