//Calculate the sum of digits by creating a function

#include<stdio.h>
int sum_of_digit(int);
int main(){
    int n;
    printf("\n Enter number: ");
    scanf("%d",&n);
    sum_of_digit(n);
}
int sum_of_digit(int n){
    int sum=0,rem;
    while(n>0){
        rem=n%10;
        n=n/10;
        sum=sum+rem;
    }
    printf("Sum of digits is: %d",sum);
}