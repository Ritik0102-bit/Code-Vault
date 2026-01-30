// In this code we are going to make a function for calculating MAX using recursion

#include<iostream>

using namespace std;

int Max_element(int arr[],int idx,int n){
    if(idx==n-1){
        return arr[idx];
    }
    return max(arr[idx],Max_element(arr,idx+1,n));
}

int main(){
    int n=5;
    int arr[]={1,15,7,12,6};
    cout << Max_element(arr,0,n);

    return 0;
}