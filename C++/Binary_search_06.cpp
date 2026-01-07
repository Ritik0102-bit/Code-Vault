// Given the rotated sorted array of integers, which contains distinct elements, and an integer target, return the index of target if it is in the array. Otherwise return -1.

// Input :
// Array = [3, 4, 5, 1, 2] , target = 4

// Output :
// 1

#include<iostream>
#include<vector>

using namespace std;

int find_target_element(vector<int> &v,int target){
    int low=0;
    int high=v.size()-1;

    while(low<=high){
        int mid=low + (high-low)/2;
        if(v[mid]==target) return mid;

        if(v[mid]>=v[low]){
            if(v[low]<=target && v[mid]>=target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(v[mid]<=target && v[high]>=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
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

    int target;
    cout << "Enter the target element: ";
    cin>>target;

    cout << find_target_element(v,target);

    return 0;
}