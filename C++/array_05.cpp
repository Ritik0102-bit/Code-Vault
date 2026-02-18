// we have two sorted arrays & we need to merge them into a array in increasing order

// Enter the elements of array1: 1,2,4,5,6
// Enter the elements of array2: 1,5,6
// final output 1 1 2 4 5 5 6 6

#include<iostream>

using namespace std;

int main(){
    int m,n;
    cout << "Enter the size of both arrays: ";
    cin >> m >> n;
    int arr1[m],arr2[n];

    cout << "Enter the elements of array1: ";
    for(int i=0;i<m;i++){
        cin>> arr1[i];
    }

    cout << "Enter the elements of array2: ";
    for(int i=0;i<n;i++){
        cin>> arr2[i];
    }
    
    int final_array[m+n];
    int i=0;
    int j=0;
    int k=0;

    while(i<m and j<n){
        if(arr1[i]<arr2[j]){
            final_array[k++]=arr1[i++];
        }
        else{
            final_array[k++]=arr2[j++];
        }
    }

    // if some elements left in the array 1
    while(i<m){
        final_array[k++]=arr1[i++];
    }
    
    // if some elements left in the array 2
    while(j<n){
        final_array[k++]=arr2[j++];
    }

    // print the final array
    for(int i=0;i<m+n;i++){
        cout << final_array[i] << " ";
    }
    
}