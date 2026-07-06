/*
Problem Statement



Manoj wants to explore numbers. The number should be even and also a multiple of 10. Write a program to obtain a number x and check if it is even or not. If even, check whether it is a multiple of 10 or not.



Function Specifications:

void iseven(int x) - Prints whether the input number is even or not.
void ismultiple(int x) - Prints whether the input number is a multiple of 10 or not.
Input format :
The input consists of an integer x.

Output format :
The first line of output displays "Even" if x is even or "Not even" otherwise.

If x is even, the second line displays "Multiple of 10" if x is a multiple of 10 or "Not a multiple of 10" otherwise.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ x ≤ 106

Sample test cases :
Input 1 :
50
Output 1 :
Even
Multiple of 10
Input 2 :
13
Output 2 :
Not even
Input 3 :
1456
Output 3 :
Even
Not a multiple of 10*/



// You are using GCC
#include<stdio.h>
void ismultiple(int n){
    if(n%10==0){
        printf("Multiple of 10");
    }
    else{
        printf("Not a multiple of 10");
    }
}
void iseven(int n){
    if(n%2==0){
        printf("Even");
        ismultiple(n);
    }
    else{
        printf("Not even");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    iseven(n);
}