#include <iostream>

using namespace std;

// Ternary search is a search algorithm that finds the position of a target value within a sorted array(nondecreasing)
int ternarySearch(int inputArray[], int target, int left, int right) {
    if (right >= left) {
        int middleOne = left + (right - left) / 3;
        int middleTwo = right - (right - left) / 3;

        if (target == inputArray[middleOne]) { // If the target value is equal to the element at the first middle index
            return middleOne; // Return the first middle index
        } else if (target == inputArray[middleTwo]) { // If the target value is equal to the element at the second middle index
            return middleTwo; // Return the second middle index
        } else if (target < inputArray[middleOne]) { // If the target value is less than the element at the first middle index
            return ternarySearch(inputArray, target, left, middleOne - 1); // Recursively perform binary search to the left of the first middle index
        } else if (target > inputArray[middleTwo]) { // If the target value is greater than the element at the second middle index
            return ternarySearch(inputArray, target, middleTwo + 1, right); // Recursively perform binary search to the right of the second middle index
        } else { // If the target value is greater than the element at the first middle index and less than the element at the second middle index
            return ternarySearch(inputArray, target, middleOne + 1, middleTwo - 1); // Recursively perform binary search between the two middle indices
        }
    } else {
        return -1; // Target value is not in the array
    }
}

int main() {
    int testArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int sizeOfTestArray = sizeof(testArray) / sizeof(testArray[0]);

    int testTarget = 8; // Target value of 8 is best case at it occurs at index 7, the middle of testArray[0...15]
    int searchResult = ternarySearch(testArray, testTarget, 0, sizeOfTestArray - 1);

    if (searchResult == -1) {
        cout << "The target value is not in the array." << endl;
    } else {
        cout << "The target value is at index " << searchResult << "." << endl;
    }

    return 0;
}