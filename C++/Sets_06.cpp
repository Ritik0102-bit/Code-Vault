// Given the number of questions as n, and marks for the correct answer as p and q marks for the incorrect answer. One can either attempt to solve the question in an examination and get either p marks if the answer is right, or q marks if the answer is wrong, or leave the question unattended and get 0 marks. The task is to find the count of all the different possible marks that one can score in the examination.

// Input 1: n = 2, p = 1, q = -1 
// Output 1: 5 
// Explanation: The different possible marks are: -2, -1, 0, 1, 2

/*
 * Logic: Iterate through all combinations of correct (x) and incorrect (y) answers.
 * * Constraints:
 * 1. 0 <= x <= n        : Correct answers cannot exceed total questions.
 * 2. 0 <= y <= n - x    : Incorrect answers cannot exceed the remaining questions.
 * 3. Unattempted        : The rest (n - x - y) contribute 0 marks.
 * * Formula: Total Score = (x * p) + (y * q)
 */

#include <iostream>
#include <set>

using namespace std;

int solve(int n, int p, int q) {
    set<int> distinct_scores;

    // Iterate through all possible numbers of correct answers (x)
    for (int x = 0; x <= n; ++x) {
        // Iterate through all possible numbers of incorrect answers (y)
        // y can range from 0 to the remaining questions (n - x)
        for (int y = 0; y <= n - x; ++y) {
            
            int current_score = (x * p) + (y * q);
            distinct_scores.insert(current_score);
        }
    }

    // The size of the set represents the count of unique scores
    return distinct_scores.size();
}

int main() {
    // Input 1 from the image
    int n = 2, p = 1, q = -1;
    cout << "Count of distinct marks: " << solve(n, p, q) << endl; 
    
    return 0;
}