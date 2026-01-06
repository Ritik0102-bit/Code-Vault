// Binary Search
// Binary search is only applicable on sorted array

// We have modified value of mid from = (low+high)/2 
// = (low + low + high -low)/2     adding and subtracting low
// = 2(low)/2  + (high-low)/2

// Mid = low + (high - low )/2

// Time = O(logn)   --> In avg & worst case
// Space = O(1)

#include<iostream>
#include<vector>

using namespace std;

int Binary_search(vector<int> &v,int target){
    int low=0;
    int high=v.size()-1;

    while(low<=high){
        // Modified value of mid value to tackle overflow 
        // Where the values of low & high are to high
        int mid=low+(high-low)/2;
        if(v[mid]==target){
            return mid;
        }
        else if(v[mid]<target){
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
    cout << "Enter the no. of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    int target;
    cout << "Enter the value of target element: ";
    cin>> target;

    int result = Binary_search(v,target);

    if(result==-1){
        cout << "Target element is not present.";
    }
    else{
        cout << "Index of target element: " << result;
    }
    
    return 0;
}