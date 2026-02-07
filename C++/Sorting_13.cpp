// Given an array where all its elements are sorted in increasing order except two swapped elements, sort it in linear time. Assume there are no duplicates in the array.

#include<iostream>
#include<vector>

using namespace std;

void sortSwappedArray(vector<int> &arr){
    int n = arr.size();
    if (n <= 1){
        return; // The array is already sorted or empty.
    }

    int first = -1;
    int last = -1;

    // Iterate through the array to find the two misplaced elements.
    for (int i = 0; i < n - 1; ++i) {
        // A "dip" indicates a misplaced element.
        if (arr[i] > arr[i + 1]) {
            if (first == -1) {
                // This is the first dip. 'arr[i]' is the first element.
                first = i;
            }
            // The second misplaced element is part of the latest dip found.
            last = i + 1;
        }
    }

    // If we found out-of-place elements, swap them back to their correct positions.
    if(first != -1){
        swap(arr[first], arr[last]);
    }

    return;
}


int main() {

    vector<int> arr = {10, 50, 30, 40, 20, 60};
    
    sortSwappedArray(arr);
    
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}