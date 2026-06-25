// The Problem Statement -> Aggressive Cows

// Imagine you have a long barn with a single straight line of N stalls. You are given the positions of these stalls as an array. You also have C aggressive cows that you need to place in these stalls.

// The key constraint is that these cows are aggressive towards each other. To prevent them from fighting, you want to place them in the stalls in such a way that the minimum distance between any two cows is as large as possible. Your task is to find this largest possible minimum distance.

// Example:

// Let's say you have 5 stalls at positions [1, 2, 8, 4, 9] and you need to place 3 cows.

// If you place the cows at positions 1, 2, and 4, the minimum distance is 1 (between 1 and 2). If you place them at 1, 2, and 8, the minimum distance is 1. If you place them at 1, 4, and 8, the distances are 3 (between 1 and 4) and 4 (between 4 and 8). The minimum distance is 3. If you place them at 1, 4, and 9, the distances are 3 and 5. The minimum distance is 3.

// The largest possible minimum distance you can achieve is 3.


#include <iostream>
#include <vector>
#include <algorithm>

// Function to check if it's possible to place 'cows' with a minimum distance of 'minDist'.
bool canPlaceCows(std::vector<int> &stalls, int cows, int minDist) {
    int cowsPlaced = 1; // Place the first cow in the first stall.
    int lastPos = stalls[0]; // Position of the last placed cow.

    // Greedily try to place the remaining cows.
    for (int i = 1; i < stalls.size(); ++i) {
        // If the current stall is at least 'minDist' away from the last placed cow.
        if (stalls[i] - lastPos >= minDist) {
            cowsPlaced++;
            lastPos = stalls[i]; // Update the position of the last placed cow.
        }
        // If we have successfully placed all cows, we can return true.
        if (cowsPlaced == cows) {
            return true;
        }
    }
    // If we couldn't place all the cows, return false.
    return false;
}

// Main function to find the largest minimum distance.
int largestMinDistance(std::vector<int> &stalls, int cows) {
    // We must sort the stalls to use a greedy approach in our check function.
    std::sort(stalls.begin(), stalls.end());

    int n = stalls.size();
    if (cows > n) return -1; // Not enough stalls for the cows.

    // Define the search space for the answer (the minimum distance).
    int low = 1; // Smallest possible minimum distance.
    int high = stalls[n - 1] - stalls[0]; // Largest possible minimum distance.
    int ans = 0;

    // Perform binary search on the answer space.
    while (low <= high) {
        int mid = low + (high - low) / 2; // To avoid integer overflow.

        if (canPlaceCows(stalls, cows, mid)) {
            // If we can place cows with distance 'mid', it's a possible answer.
            // We try for an even larger distance.
            ans = mid;
            low = mid + 1;
        } else {
            // If we can't, the distance 'mid' is too large.
            // We must try a smaller distance.
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    std::vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    int result = largestMinDistance(stalls, cows);
    std::cout << "The largest minimum distance is: " << result << std::endl; // Output: 3
    return 0;
}