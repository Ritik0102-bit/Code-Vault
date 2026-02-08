// Given an array of positive and negative integers, segregate them without changing the relative order of elements. The output should contain all negative numbers followed by all positive numbers while maintaining the same relative ordering.

// Input : {-12, 11, -13, -5, 6, -7, 5, -3, -6}
// Expected Output: -12 -13 -5 -7 -3 -6 11 6 5

// 1st Method
// It's a efficient Method

// Time : O(n^2)
// Space : O(1)

#include <iostream>
#include <vector>

using namespace std;

void segregateInPlaceStable(std::vector<int>& arr) {
    int n = arr.size();
    
    // Iterate through the array starting from the second element.
    for (int i = 1; i < n; ++i) {
        // If the current element is negative, it needs to be moved
        // to the end of the "negative" section.
        if (arr[i] < 0) {
            int key = arr[i]; // The negative number to be inserted.
            int j = i - 1;

            // Shift all positive numbers that are before the key one position to the right.
            // This loop makes space for the key.
            while (j >= 0 && arr[j] >= 0) {
                arr[j + 1] = arr[j];
                j--;
            }

            // Place the key in its correct sorted position.
            arr[j + 1] = key;
        }
    }
}

int main() {
    int n;
    cout<<"Enter the no. of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    segregateInPlaceStable(v);
    
    for(int i=0;i<n;i++){
        cout << v[i] << "  ";
    }

    return 0;
}




// 2nd Method 
// It's not efficient
// Time : O(n)
// Space : O(n)

// #include <iostream>
// #include<vector>

// using namespace std;

// int main(){
//     int n;
//     cout<<"Enter the no. of elements: ";
//     cin >> n;

//     vector<int> v(n);
//     cout << "Enter the elements: ";
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
    
//     vector<int> ans(n);
//     int k=0;
//     for (int i=0;i<n;i++){
//         if(v[i]<0){
//             ans[k++]=v[i];
//         }
//     }
//     for (int i=0;i<n;i++){
//         if(v[i]>=0){
//             ans[k++]=v[i];
//         }
//     }
    
//     for(int i=0;i<n;i++){
//         cout << ans[i] << "  ";
//     }
    
//     return 0;
// }
