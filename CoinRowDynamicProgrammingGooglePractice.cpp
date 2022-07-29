#include <iostream>
#include <vector>

using namespace std;

int findMax(int numOne, int numTwo) {
    if (numOne > numTwo) {
        return numOne;
    } else {
        return numTwo;
    }
}

int coinRow(vector<int>& coins, int size) {
    // Return the first coin if there is only one
    if (size == 1 ) {
        return coins[1];
    }

    // Return the max of the first two coins if there is only two
    if (size == 2) {
        return findMax(coins[1], coins[2]);
    }

    vector<int> F(size);
    F[0] = 0; // F[0] is the amount that can be picked up from 0 coins, which is of course 0
    F[1] = coins[1]; // F[1] starts as the first coin since we are building up from left to right
    for (int i = 2; i < size; i++) {
        // Pikc the max between the first group coins[n] + F(n - 2) and second group F(n - 1)
        F[i] = findMax(coins[i] + F[i - 2], F[i - 1]); 
    }

    return F[size - 1]; // Return amount that can be picked up from the row of coins
}

using namespace std;

int main() {
    vector<int> coins = {0, 5, 1, 2, 10, 6, 2};
    int size = coins.size();

    int solution = coinRow(coins, size);
    cout << "Maximum amount of money from picking up nonadjacent coins: " << solution << endl;
}
