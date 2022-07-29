#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h> 

using namespace std;

// Class to represent a point in a 2D plane
class Point {
    public:
        int x;
        int y;
};

// Used to sort points according to x coords
bool compareX(Point pointOne, Point pointTwo) {
    return pointOne.x < pointTwo.x;
}

// Used to sort points according to y coords
bool compareY(Point pointOne, Point pointTwo) {
    return pointOne.y < pointTwo.y;
}

// Used to calculate euclidean distance between two points
float findDist(Point pointOne, Point pointTwo) {
    float dx = pointOne.x - pointTwo.x;
    float dy = pointOne.y - pointTwo.y;

    return sqrt((dx * dx) + (dy * dy));
}

// Used to find the minimum between two values
float findMin(float a, float b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// Brute force algorithm to find the closest pair of points
float closestPointsBruteForce(vector<Point>& points, int size) {
    float min = FLT_MAX;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            min = findMin(findDist(points[j], points[i]), min);
        }
    }
    
    return min;
}

// Finds the distance between the closest points in strip of a given size 
// All points in strip are sorted according to y coordinate 
// They all have an upper bound on minimum distance as d
// Appears to be O(n^2) but it is O(n) as the inner loop runs at most 6 times
float closestPointsStrip(vector<Point>& strip, int size, float d) {
    float min = d;

    // Pick every point and try the next point until the difference between y coordinates is smaller than d
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; j++) {
            min = findMin(findDist(strip[j], strip[i]), min);
        }
    }

    return min;
}

// A recursive function to find the smallest distance 
// pointsX contains all points sorted by x coords and pointsY contains all points sorted by y coords
float closestPointsHelper(vector<Point>& pointsX, vector<Point>& pointsY, int size) {
    // Base case : use brute force if there are only 2 or 3 points
    if (size <= 3) {
        return closestPointsBruteForce(pointsX, size);
    }
    
    // Get the middle point
    int middleIdx = size / 2;
    Point middlePoint = pointsX[middleIdx];

    vector<Point> pointsYLeft; // Sorted y points on left of vertical line
    vector<Point> pointsYRight; // Sorted y points on right of vertical line
    int leftIdx = 0; // Index of left sub array
    int rightIdx = 0; // Index of right sub array

    // Divide points in sorted y array around the vertical line
    // Assumes that all x coordinates are distinct
    for (int i = 0; i < size; i++) {
        if ((pointsY[i].x < middlePoint.x || (pointsY[i].x == middlePoint.x && pointsY[i].y < middlePoint.y)) && leftIdx < middleIdx) {
            pointsYLeft.push_back(pointsY[i]);
            rightIdx++;
        } else {
            pointsYRight.push_back(pointsY[i]);
            rightIdx++;
        }
    }

    // Consider the vertical line passing through the middle point
    // Calculate the smallest distance dLeft on left of middle point and dRight on right side
    float dLeft = closestPointsHelper(pointsX, pointsYLeft, middleIdx);
    float dRight = closestPointsHelper(pointsX, pointsYRight, size - middleIdx);

    float d = findMin(dLeft, dRight); // Find the minimum d of these two distances

    // Build strip which contains points closer than d to the line passing through the middle point
    vector<Point> strip;
    for (int i = 0; i < size; i++) {
        if (abs(pointsY[i].x - middlePoint.x) < d) {
            strip.push_back(pointsY[i]);
        }
    }

    // Find the closest points in strip and return the minimum of the closest distance in strip and d
    return closestPointsStrip(strip, strip.size(), d);
}

// Finds the smallest distance mainly by calling closestPointsHelper
float closestPoints(vector<Point>& points, int size) {
    vector<Point> pointsX;
    vector<Point> pointsY;

    for (int i = 0; i < size; i++) {
        pointsX.push_back(points[i]);
        pointsY.push_back(points[i]);
    }

    sort(pointsX.begin(), pointsX.end(), compareX); // Sort all points according to x coords
    sort(pointsY.begin(), pointsY.end(), compareY); // Sort all points according to y coords

    return closestPointsHelper(pointsX, pointsY, size); // Call recursive function cloesestPointsHelper to find the smallest distance
}

int main() {
    vector<Point> points = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
    int size = points.size();

    cout << "The smallest distance is " << closestPoints(points, size);

    return 0;
}
