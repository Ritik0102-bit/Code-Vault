// Find the square root of a non negative value of x . Round it of to the nearest floor integer value.

// Input : x=4
// Output : 2

// Input : x=11
// Output : 3

// Time : O(logx)
// Space : O(1)

#include<iostream>

using namespace std;

int Square_root(int x){
    int low=1;
    int high=x;

    int ans=1;

    while(low<=high){
        int mid=low + (high - low)/2;
        if((mid*mid)<=x){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int x;
    cout << "Enter the value of x: ";
    cin>>x;

    cout << Square_root(x);

    return 0;
}