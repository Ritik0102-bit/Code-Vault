// In this code we are going to merge two sorted arrays to make a new sorted array

#include<iostream>

using namespace std;

void Merge_array(int arr1[],int n1,int arr2[],int n2,int arr3[]){
    int i=0;
    int j=0;
    int k=0;
    
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }

    while(i<n1){
        arr3[k++]=arr1[i++];
    }
    while(j<n2){
        arr3[k++]=arr2[j++];
    }
    
    return;
}

int main(){
    int arr1[]={1,4,7,9,10};
    int arr2[]={2,4,5,6,11};

    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);

    int arr3[n1+n2];

    Merge_array(arr1,n1,arr2,n2,arr3);

    for(int i=0;i<n1+n2;i++){
        cout << arr3[i] << "  ";
    }

    return 0;
}