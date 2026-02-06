// Merge Sort

// Time Complexity: O(nlogn) in all cases (best, average, and worst).
// Space Complexity: O(n) , because it needs extra space for two sub-arrays

// It's slow for small problems

// It's a stable sorting algorithm

#include<iostream>

using namespace std;

void Merge(int arr[],int start,int mid,int last){
    // we need to make two sub_arrays
    int n1=mid-start+1;
    int n2=last-mid;

    int arr1[n1];
    int arr2[n2];

    for(int i=0;i<n1;i++){
        arr1[i]=arr[i+start];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[i+mid+1];
    }

    // Now we merge these two sub arrays in correct order
    int i=0;
    int j=0;
    int k=start;

    while(i<n1 && j<n2){
        if(arr1[i]>=arr2[j]){
            arr[k++]=arr2[j++];
        }
        else{
            arr[k++]=arr1[i++];
        }
    }
    while(i<n1){
        arr[k++]=arr1[i++];
    }
    while(j<n2){
        arr[k++]=arr2[j++];
    }
}


void Merge_sort(int arr[],int start,int last){
    if(start>=last){
        return;
    }
    int mid=(start+last)/2;
    Merge_sort(arr,start,mid);
    Merge_sort(arr,mid+1,last);
    Merge(arr,start,mid,last);
}

int main(){
    int n;
    cout << "Enter the no. of elements in the array: ";
    cin>> n;

    int arr[n] ;
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }

    Merge_sort(arr,0,n-1);

    for(int i=0;i<5;i++){
        cout << arr[i]  << "  ";
    }
}