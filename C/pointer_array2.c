// Write a program to enter 10 element in double array.
// using pointer to array display elements in reverse order.

#include<stdio.h>
int main(){
    double arr[10];
    double *ptr=&arr[0];
    for(int i=0;i<10;i++){
        scanf("%lf",ptr+i);
    }
    for(int i=9;i>=0;i--){
        printf("%lf \n",*(ptr+i));
    }
}