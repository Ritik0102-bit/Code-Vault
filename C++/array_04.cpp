// WAP to sort a array of 0s and 1s 
// like  0 1 0 0 1 0 1 1
// output 0 0 0 0 1 1 1 1

#include<iostream>

using namespace std;

void sorting_array(int arr[],int n){
    int left_pointer=0;
    int right_pointer=n-1;
    
    while(left_pointer<right_pointer){
        if(arr[left_pointer]==1 && arr[right_pointer]==0){
            arr[left_pointer++]=0;
            arr[right_pointer--]=1;
        }
        if(arr[left_pointer]==0){
            left_pointer++;
        }
        if(arr[right_pointer]==1){
            right_pointer--;
        }
    }
}

int main(){
    int n;
    cout << "Enter the size of array : " ;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    
    sorting_array(arr,n);

    for(int i=0;i<n;i++){
        cout <<  arr[i] << " ";
    }
}