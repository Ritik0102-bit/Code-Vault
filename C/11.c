//Calculate the sum of digits
#include<stdio.h>
int main(){
    int n,sum=0;
    int rem;
    printf("\n Enter number: ");
    scanf("%d",&n);
    while(n>0){
        rem=n%10;
        n=n/10;
        sum=sum+rem;
    }
    printf("Sum of digits is: %d",sum);
}