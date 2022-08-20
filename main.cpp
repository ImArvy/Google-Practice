/*
You are given a start time and an end time
Check if this start and end time can be booked by calling the book() method
Return true if the time can be booked and false if it cannot
*/

// start is between bookedTimes[i].first and bookedTimes[i].second
// [10, 30] 
// [15, 30]

// end is between bookedTimes[i].first and bookedTimes[i].second
// [10, 30] 
// [ 5, 20]

// start is before bookedTimes[i].first and end is after bookedTimes[i].second
// [10, 30] 
// [ 5, 40]

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

class Solution {
private:
	vector<pair<int, int>> bookedTimes;
public:
	void print();
	bool book(int, int);
};

void Solution::print() {
	if (bookedTimes.size() == 0) {
		cout << "No booked times!" << endl;
	} else {
		for (int i = 0; i < bookedTimes.size(); i++) {
			cout << "[" << bookedTimes[i].first << " , " << bookedTimes[i].second << "] ";
		}

		cout << endl;
	}
}

bool Solution::book(int start, int end) {
	// Base case where there are no times booked so far
	if (bookedTimes.size() == 0) {
		bookedTimes.push_back(make_pair(start, end));
		return true;
	}

	// Traverse through bookedTimes and compare to start and end
	for (int i = 0; i < bookedTimes.size(); i++) {
		// If start is between the start of a booked time and end of a booked time
		if (start >= bookedTimes[i].first && start <= bookedTimes[i].second) {
			return false; // Overlap
		} 
		// If end is between the start of a booked time and end of a booked time
		else if (end >= bookedTimes[i].first && end <= bookedTimes[i].second) {
			return false; // Overlap
		}
		// If start is before the start of a booked time and end is after then end of a booked time
		else if (start <= bookedTimes[i].first && end >= bookedTimes[i].second) {
			return false; // Overlap
		}
	}

	bookedTimes.push_back(make_pair(start, end)); // Push valid booking to bookedTimes

	return true; // Return true if there is no overlap in the schedule
}

int main() {
	Solution solution;

	solution.book(10, 30);
	solution.print(); // 10 and 30 are booked

	solution.book(11, 29);
	solution.print(); // 11 and 29 are not booked

	solution.book(15, 30);
	solution.print(); // 15 and 30 are not booked

	solution.book(5, 20);
	solution.print(); // 5 and 20 are not booked

	solution.book(5, 40);
	solution.print(); // 5 and 40 are not booked

	solution.book(1, 9);
	solution.print(); // 5 and 8 are booked

	solution.book(31, 40);
	solution.print(); // 31 and 40 are booked

	solution.book(32, 39);
	solution.print(); // 32 and 39 are not booked

	solution.book(41, 50);
	solution.print(); // 41 and 50 are booked

	return 0;
}