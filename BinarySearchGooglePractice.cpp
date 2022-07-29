#include <iostream>

using namespace std;

// Binary search is a search algorithm that finds the position of a target value within a sorted array(nondecreasing)
int binarySearch(int inputArray[], int target, int left, int right) {
    if (right >= left) {
        int middle = left + (right - left) / 2;

        cout << left << ' ' << middle << ' ' << right << endl;

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

int main() {
    int testArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int sizeOfTestArray = sizeof(testArray) / sizeof(testArray[0]);

    int testTarget = 8; // Target value of 8 is best case at it occurs at index 7, the middle of testArray[0...15]
    int searchResult = binarySearch(testArray, testTarget, 0, sizeOfTestArray - 1);

    if (searchResult == -1) {
        cout << "The target value is not in the array." << endl;
    } else {
        cout << "The target value is at index " << searchResult << "." << endl;
    }

    return 0;
}