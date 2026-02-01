// In this code we are going to make a function for printing sum of all subsets in an array using recursion

// arr[]={2,3}
// output : 0 2 3 5

// arr[]={2,4,5}
// output: 0 2 4 5 6 7 9 11

// No. of subsets = 2^n
// for each element in a set there are two ways to calculate subsets
// first by including it  &  second by not including it

#include<iostream>
#include<vector>

using namespace std;

int subsets_sum(int arr[],int i,int n,int sum,vector <int> &result){
    // Base Case
    if(i==n){
        result.push_back(sum);
        return 0;
    }

    subsets_sum(arr,i+1,n,sum+arr[i],result);
    subsets_sum(arr,i+1,n,sum,result);
}

int main(){
    int n;
    cout << "Enter the no. of elements in the array : ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the value of elements in the array : ";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    
    vector<int> result;
    
    subsets_sum(arr,0,n,0,result);
    
    cout << "Sum of subsets in the array : ";
    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }

    return 0;
}