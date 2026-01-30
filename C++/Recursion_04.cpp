// In this code we are going to make a function for calculating sum of elements in an array using recursion

#include<iostream>

using namespace std;

int Sum_of_elements(int arr[],int idx,int n){
    if(idx==n){
        return arr[idx];
    }
    else{
        return arr[idx] + Sum_of_elements(arr,idx+1,n);
    }
}

int main(){
    int n=5;
    int arr[n]={2,4,7,9,10};
    cout << " Sum_of_elements is : " << Sum_of_elements(arr,0,n-1);
}