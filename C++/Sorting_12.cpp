// Write a Program to find Kth smallest element in an array using QuickSort.

// Input
// Enter the elements of array
// 3 5 2 1 4 7 8 6
// Enter the value for k
// 5

// Output
// K'th smallest element is 5


#include<iostream>

using namespace std;

int partition(int arr[], int l, int r){
  int pivot = arr[r];
  int i=l;
  for(int j=l; j<r; j++){
    if(arr[j]<pivot){
      swap(arr[i],arr[j]);
      i++;
    }
  }
  swap(arr[i],arr[r]);
  return i;
}

int kthSmallest(int arr[], int l, int r, int k){

  if(k>0 && k<=r-l+1){
    
    int pos = partition(arr,l,r); //position of pivot ele

    if(pos-l==k-1){
      return arr[pos];
    }
    else if(pos-l>k-1){
      return kthSmallest(arr,l,pos-1,k);
    }
    else{
      return kthSmallest(arr,pos+1,r,k-(pos-l+1));
    }
  }

  return INT8_MAX;
}

int main(){
    int n;
    cout << "Enter the no. of elements: ";
    cin>> n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    cout << kthSmallest(arr,0,n-1,k);
    
    return 0;
}