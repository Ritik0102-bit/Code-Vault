#include<stdio.h>
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<5;i++){
        printf("Value: %d , index Value : %d , Memory location : %u \n",arr[i],i,&arr[i]);
        printf("square of each value: %d \n",arr[i]*arr[i]);
    }
    return 0;
}