// The Book Allocation Problem is a classic algorithm question that demonstrates an efficient way to minimize a maximum value, making it a prime example of using binary search on the answer space.

// Imagine you have a set of N books with varying numbers of pages, and you need to distribute them among M students. The books must be allocated in a contiguous manner. Your goal is to find an allocation scheme that minimizes the maximum number of pages any single student has to read. The answer is this minimized maximum number.

// An Illustrative Example 🧑‍🏫
// Let's say you have 4 books with pages [10, 20, 30, 40] and 2 students.

// Here are a few possible ways to allocate the books:

// Student 1: [10] (10 pages) Student 2: [20, 30, 40] (90 pages) The maximum pages a student reads is 90.

// Student 1: [10, 20] (30 pages) Student 2: [30, 40] (70 pages) The maximum pages a student reads is 70.

// Student 1: [10, 20, 30] (60 pages) Student 2: [40] (40 pages) The maximum pages a student reads is 60.

// The best possible allocation is the last one because it results in the smallest possible maximum, which is 60. This is the answer we are looking for.


#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
#include <algorithm>

using namespace std;

// Helper function to check if it's possible to allocate books 
// such that no student reads more than 'maxPagesAllowed'.
bool isPossible(vector<int>& books, int m, int maxPagesAllowed) {
    int studentsCount = 1;
    int pagesSum = 0;

    for (int i = 0; i < books.size(); i++) {
        // If a single book has more pages than the limit, it's impossible.
        if (books[i] > maxPagesAllowed) return false;

        if (pagesSum + books[i] <= maxPagesAllowed) {
            // Assign book to the current student
            pagesSum += books[i];
        } else {
            // Assign book to the next student
            studentsCount++;
            pagesSum = books[i];

            // If students required exceed available students, return false
            if (studentsCount > m) return false;
        }
    }
    return true;
}

int allocateBooks(vector<int>& books, int n, int m) {
    // If books are fewer than students, allocation is impossible 
    // (assuming each student must get at least one book).
    if (m > n) return -1;

    int sum = 0;
    int maxElement = 0;
    for (int pages : books) {
        sum += pages;
        maxElement = max(maxElement, pages);
    }

    // Binary Search Range
    int low = maxElement; // Min possible answer: largest single book
    int high = sum;      // Max possible answer: all books to one student
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(books, m, mid)) {
            // If possible, 'mid' could be our answer. 
            // We look for a smaller 'maximum' (move left).
            ans = mid;
            high = mid - 1;
        } else {
            // If not possible, we need to increase the limit (move right).
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    int n = books.size();

    cout << "Minimum possible maximum pages: " << allocateBooks(books, n, students) << endl;
    return 0;
}