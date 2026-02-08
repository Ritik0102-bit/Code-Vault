// Given an array of positive and negative integers, segregate them in linear time and constant space. The output should print negative numbers, followed by all positive numbers.

// In this problem Relative order is not necessary

#include<iostream>

using namespace std;

void sort_array(int arr[],int n){
    int left=0;
    int right=n-1;

    while(left<=right){
        if(arr[left]<0){
            left++;
        }
        else{
            swap(arr[right--],arr[left]);
        }
    }

    return;
}

int main(){
    int arr[]={1,2,4,-5,0,-4,5,-6,7};

    int n=sizeof(arr)/sizeof(arr[0]);

    sort_array(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << "  ";
    }

    return 0;
}