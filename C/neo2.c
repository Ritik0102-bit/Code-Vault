// Octal coversion of a number
// Problem Statement



// Arjun is working on a program that helps him convert numbers from one number system to another. Today, he has been given the task of converting a number from octal (base 8) to decimal (base 10).



// As part of this task, he needs to write a program that takes an octal number as input and computes its equivalent decimal number.

// Input format :
// The input consists of an integer N, representing the octal number.

// Output format :
// The output prints an integer representing the equivalent decimal number.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 103

// Sample test cases :
// Input 1 :
// 1
// Output 1 :
// 1
// Input 2 :
// 150
// Output 2 :
// 104
// Input 3 :
// 512
// Output 3 :
// 330



#include<stdio.h>
int main(){
    int n,dec=0,b=1,rem;
    scanf("%d",&n);
    while(n>0){
        rem=n%10;
        dec+=rem*b;
        n/=10;
        b*=8;
    }
    printf("%d",dec);
    return 0;
}