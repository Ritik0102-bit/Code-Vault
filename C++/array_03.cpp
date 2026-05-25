// WAP to find second largest number in the array

#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int max=INT64_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    int secondMax=INT64_MIN;
    for(int i=0;i<n;i++){
        if(secondMax<arr[i] && arr[i]!=max){
            secondMax=arr[i];
        }
    }
    cout << secondMax;
}