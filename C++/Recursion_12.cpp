// In this code we are going to solve FROG JUMP PROBLEM using recursion

// There are N stones, numbered 1,2,...,N. For each i (1≤i≤N), the height of Stone i is hi
// ​
//There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

// If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣hi−hj∣ is incurred, where j is the stone to land on.

// Find the minimum possible total cost incurred before the frog reaches Stone N.

// Input n= 4
// arr[] = 10 30 40 20
// Output= 30

#include<iostream>

using namespace std;

int frog_jump(int n,int arr[],int i){

    if(i==n-1) return 0;  // Base case

    if(i==n-2) return frog_jump(n,arr,i+1) + abs(arr[i]-arr[i+1]);  // Base case

    return min(frog_jump(n,arr,i+1) + abs(arr[i]-arr[i+1]) , frog_jump(n,arr,i+2) + abs(arr[i]-arr[i+2]));
}

int main(){
    int n;
    cout << "Enter the no. of stones : ";
    cin >> n;

    int arr[n];
    cout << "Enter the value of Stones : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "The Minimum Possible cost is : " << frog_jump(n,arr,0);

}