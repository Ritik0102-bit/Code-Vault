#include<stdio.h>
int ispresent(int arr[],int size,int ele){
    for(int i=0;i<size;i++){
        if(arr[i]==ele){
            return 1; // Element found
        }
    }
    return 0; // Element not found
}

int main(){
    int arr[5];
    int arr1[5];
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<5;i++){
        scanf("%d",&arr1[i]);
    }
    int unionsize=0;
    int unionarr[100];

    // Copy all elements of arr1
    for(int i=0;i<5;i++){
        if(!ispresent(unionarr,unionsize,arr[i])){
            unionarr[unionsize++]=arr[i];
        }
    }

    // Copy all unique elements from arr2
    for(int i=0;i<5;i++){
        if(!ispresent(unionarr,unionsize,arr1[i])){
            unionarr[unionsize++]=arr1[i];
        }
    }

    // Print union
    printf("Union of arrays: ");
    for(int i=0;i<unionsize;i++){
        printf("%d ",unionarr[i]);
    }
}