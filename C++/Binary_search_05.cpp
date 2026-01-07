// A rotated sorted array is a sorted array on which rotation operation has been performed some number of times. Given a rotated sorted array, find the index of the minimum element in the array. Follow 0-based indexing.

// It is guaranteed that all the elements in the array are unique.

// Input :
// Array = [3, 4, 5, 1, 2]

// Output :
// 3


// A rotated sorted array is an array that was originally sorted in ascending order and then had a block of elements shifted from one end to the other.

// Let's start with a simple sorted array:
// [0, 1, 2, 4, 5, 6, 7]

// Now, let's rotate it by 3 positions to the right. We take the first 3 elements [0, 1, 2] and move them to the end:

// Original: [0, 1, 2, 4, 5, 6, 7]

// Becomes: [4, 5, 6, 7, 0, 1, 2]

// The resulting array [4, 5, 6, 7, 0, 1, 2] is a rotated sorted array.

#include<iostream>
#include<vector>

using namespace std;

int find_minimum_element(vector<int> &v){
    int low=0;
    int high=v.size()-1;

    if(v[low]<v[high]){
        return low;
    }

    while(low<=high){
        int mid=low + (high-low)/2;
        if(v[mid]>v[mid+1]) return mid+1;
        if(v[mid]<v[mid-1]) return mid;
        if(v[mid]>v[low]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return -1;
}

int main(){
    int n;
    cout<<"Enter the no. of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout << find_minimum_element(v);

    return 0;
}