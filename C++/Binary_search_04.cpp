// Given an array of integers 'a' that is sorted in non-decreasing order. Find the first and the last position of the given 'target' element in the sorted array. Follow 0-based indexing.

// If 'target' is not found in the array, return [-1, -1].

// Input :
// Array = [1, 2, 3, 3, 3, 5, 11], target = 3

// Output :
// [2, 4]

#include<iostream>
#include<vector>

using namespace std;

int first_occurence(vector<int> &v,int target){
    int low=0;
    int high=v.size()-1;
    int first_pos=-1;

    while(low<=high){
        int mid=low + (high-low)/2;
        if(v[mid]==target){
            first_pos=mid;
            high=mid-1;
        }
        else if(v[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first_pos;
}


int last_occurence(vector<int> &v,int target){
    int low=0;
    int high=v.size()-1;
    int last_pos=-1;

    while(low<=high){
        int mid=low + (high-low)/2;
        if(v[mid]==target){
            last_pos=mid;
            low=mid+1;
        }
        else if(v[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return last_pos;
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

    cout << "First Position: " << first_occurence(v,target) << endl;
    cout << "Last Position: " << last_occurence(v,target)  << endl;

    return 0;
}