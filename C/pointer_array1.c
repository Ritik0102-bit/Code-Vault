// Write a program to enter 10 int element in array.
// using pointer to array calculate sum of all even values in array using pointer.

#include<stdio.h>
int main(){
    int arr[10];
    int s=0;
    int *ptr=&arr[0];
    for(int i=0;i<10;i++){
        scanf("%d",ptr+i);
    }
    for(int i=0;i<10;i++){
        if(*(ptr+i)%2==0){
            s+=*(ptr+i);
        }
    }
    printf("%d",s);
}