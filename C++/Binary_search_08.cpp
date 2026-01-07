// Given a mountain array 'a' of length greater than 3, return the index 'i' such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]. This index is known as the peak index.

// Input :
// Array = [0, 4, 1, 0]

// Output :
// 1

#include<iostream>
#include<vector>

using namespace std;

int find_peak_element(vector<int> &v){
    int low=1;
    int high=v.size()-1;

    int ans=-1;

    while(low<=high){
        int mid=low + (high-low)/2;
        if(v[mid]>v[mid-1]){
            ans=max(ans,mid);
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
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

    cout << v[find_peak_element(v)] ;

    return 0;
}