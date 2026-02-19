// we have a array of negative and positive integers 
// we need array of their squares needs to be arranged in increasing order

#include<iostream>

using namespace std;

int main(){
    int arr[8]={-4,-3,0,1,2,5,6,7};
    int square_arr[8];

    // we are using two pointer approach
    int i=0;
    int j=8-1;
    int k=8-1;

    while(i<=j){
        if(abs(arr[i])>abs(arr[j])){
            square_arr[k--]=arr[i]*arr[i++];
        }
        else{
            square_arr[k--]=arr[j]*arr[j--];
        }
    }

    for(int i=0;i<8;i++){
        cout << square_arr[i] << "  ";
    }
}