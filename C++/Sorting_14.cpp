// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// This is a classic problem known as the Dutch National Flag Problem. The goal is to sort the array in a single pass.

// Best Approach: Three-Way Partitioning

// This algorithm uses three pointers—low, mid, and high—to partition the array into three sections: 0s, 1s, and 2s.

// Initialize Pointers:

// low = 0

// mid = 0

// high = n - 1 (where n is the array size)

// Iterate and Partition: Loop as long as mid <= high.

// If arr[mid] == 0: The element belongs in the low section. Swap arr[low] with arr[mid] and increment both low and mid.

// If arr[mid] == 1: The element is already in its correct potential section. Just move to the next element by incrementing mid.

// If arr[mid] == 2: The element belongs in the high section. Swap arr[mid] with arr[high] and decrement high. (Do not increment mid, as the new arr[mid] needs to be processed).

// time complexity : O(N) 
// space complexity : O(1)

#include<iostream>

using namespace std;

void sort_array(int arr[],int n){
    int low =0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low++],arr[mid++]);
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high--]);
        }
    }
    return;
}

int main(){
    int arr[]={2,1,2,1,2,2,1,0,2,0,1};
    
    int n=sizeof(arr)/sizeof(arr[0]);

    sort_array(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << "  ";
    }

    return 0;
}