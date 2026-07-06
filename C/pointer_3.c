// write a program to reverse a number using pointer to value
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int *ptr;
    ptr=&n;
    int reverse=0;
    while(n>0){
        int rem=*ptr%10;
        reverse=reverse*10+rem;
        *ptr/=10;
    }
    printf("%d",reverse);
    return 0;
}