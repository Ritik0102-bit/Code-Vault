// Find the first occurrence of a given element x, given that the given array is sorted.
// If no occurrence of x is found then return -1.

// Input
// arr = [2, 5, 5, 5, 6, 8, 9, 9, 9]
// x = 5

// Output
// 1

#include<iostream>
#include<vector>

using namespace std;

int first_occurence(vector<int> &v,int target){
    int low=0;
    int high=v.size()-1;
    
    int ans=-1;

    while(high>=low){
        int mid=low + (high-low)/2;
        if(v[mid]==target){
            ans=mid;
            high=mid-1;
        }
        else if(v[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){

    vector<int> v(10);
    v={2, 5, 5, 5, 6, 6, 8, 9, 9, 9};

    int x=9;

    cout << first_occurence(v,x);

    return 0;
}