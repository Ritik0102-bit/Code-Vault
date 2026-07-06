#include<stdio.h>
void palindrome(int);
int main(){
    int n;
    scanf("%d",&n);
    palindrome(n);
}
void palindrome(int n){
    int temp=n;
    int reverse=0;
    while(n>0){
        int rem=n%10;
        reverse=reverse*10+rem;
        n/=10;
    }
    if(temp==reverse)
    printf("It is a Palindrome.");
    else
    printf("It is not a Palindrome.");
}