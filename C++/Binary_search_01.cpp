// Binary Search
// Binary search is only applicable on sorted array

// It's a recursive approach

// Time = O(logn)
// Space = O(logn)

#include<iostream>

using namespace std;

int Binary_search(int arr[],int low,int high,int target){
    // Modified value of mid value to tackle overflow 
    // Where the values of low & high are to high
    int mid=(low+high)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]<target){
        return Binary_search(arr,mid+1,high,target);
    }
    else if(arr[mid]<target){
        return Binary_search(arr,low,mid-1,target);
    }
    else{
        return -1;
    }
}

int main(){
    int n;

    int arr[]={1,5,7,9,11,23,25,27,30};

    cout << Binary_search(arr,0,8,2);

    return 0;
}