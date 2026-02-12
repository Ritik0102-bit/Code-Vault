// Largest Rectangular Area in a Histogram

// Given an array of integer heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// 1st Approach -> Average Approach(Solved In 3 Passes)

// Find the PSE indices for the entire array (Left Boundary).
// Find the NSE indices for the entire array (Right Boundary).
// Loop through every bar, calculate (NSE - PSE - 1) * height, and track the maximum area found.

// Ex : [2, 1, 5, 6, 2, 3, 2, 1, 10, 2, 3]

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include<climits>

using namespace std;

// 1. Standard Previous Smaller Element (Stores INDICES)
vector<int> getPSE(vector<int>& heights) {
    int n = heights.size();
    vector<int> pse(n, -1); // Default boundary is -1 (start of array - 1)
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

// 2. Standard Next Smaller Element (Stores INDICES)
vector<int> getNSE(vector<int>& heights) {
    int n = heights.size();
    vector<int> nse(n, n); // Default boundary is n (end of array)
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) { // Iterating Right to Left is often cleaner for NSE
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    
    // Step 1 & 2: Get boundaries
    vector<int> pse = getPSE(heights);
    vector<int> nse = getNSE(heights);
    
    int maxArea = 0;

    // Step 3: Calculate area for each bar
    for (int i = 0; i < n; i++) {
        int height = heights[i];
        
        // Formula: Width = RightBoundary - LeftBoundary - 1
        int width = nse[i] - pse[i] - 1;
        
        int area = height * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// 2nd Approach ->  Best Approach (In Single Pass)

// How it Works (The "On-The-Fly" Logic)
// Instead of pre-calculating boundaries, you calculate the area at the exact moment you pop an element.
// When do we pop? When we see a bar arr[i] that is smaller than the bar at st.top().
// What does this mean?
// The bar arr[i] is the Right Boundary (NSE) for the popped element because it's the first smaller element to the right.
// The new st.top() (after popping) is the Left Boundary (PSE) for the popped element because the stack is strictly increasing.

// Result: You have the Height, the Left Boundary, and the Right Boundary all available instantly. You calculate the area right then and there.

// The second while loop handles the elements remaining in the stack. These are the elements that never found a "smaller element to the right." Therefore, their Right Boundary (nsi) is the end of the array (n).

int histogram(vector<int> &arr) {
    int n = arr.size();
    stack<int> st; // indexes
    int ans = INT_MIN;
    st.push(0);
    for(int i = 1; i < n; i++) {
        while(!st.empty() and arr[i] < arr[st.top()]) {
            int el = arr[st.top()]; // current bar to be removed and whose ans will be calc
            st.pop();
            int nsi = i;
            int psi = (st.empty()) ? -1 : st.top();
            ans = max(ans, el*(nsi - psi - 1));
        }
        st.push(i);
    }
    while(not st.empty()) {
        int el = arr[st.top()];
        st.pop();
        int nsi = n;
        int psi = (st.empty()) ? (-1) : st.top();
        ans = max(ans, el*(nsi - psi - 1));
    }
    return ans;
}

// 3rd Approach : More clean code for 2nd approach

int histogram_2(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    int ans = 0; // Use 0, not INT_MIN (area can't be negative)

    for (int i = 0; i <= n; i++) {
        // Trick: Iterate to n. 
        // If i == n, treat it as a height of 0.
        // This forces the stack to empty completely in one loop, 
        // eliminating the need for the second "cleanup" while loop!
        int currentHeight = (i == n) ? 0 : arr[i];

        while (!st.empty() && currentHeight < arr[st.top()]) {
            int height = arr[st.top()];
            st.pop();
            
            int nsi = i;
            int psi = st.empty() ? -1 : st.top();
            
            ans = max(ans, height * (nsi - psi - 1));
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << "Max Area: " << largestRectangleArea(v) << endl; 
    cout << "Max Area: " << histogram(v) << endl; 
    cout << "Max Area: " << histogram_2(v) << endl; 
    // Output should be 10 (Using heights 5 and 6, limited to height 5. Width=2. 5*2=10)
    
    return 0;
}
