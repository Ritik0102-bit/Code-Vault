// Problem Statement



// In a digital library system, each book is assigned a unique identification number for tracking and inventory purposes. Develop a C program that validates the integrity of these identification numbers using the product of their digits. 



// For instance, if a book's identification number is 1234, the program should calculate the product of these digits (1 * 2 * 3 * 4) and return the result.

// Input format :
// The input consists of a long long integer n, representing the unique identification number.

// Output format :
// The output prints the product of its digits as a long long integer.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the given test cases fall under the following constraints:

// 104 ≤ n ≤ 1011

// Sample test cases :
// Input 1 :
// 54321
// Output 1 :
// 120
// Input 2 :
// 12986574325
// Output 2 :
// 3628800
// Input 3 :
// 865324
// Output 3 :
// 5760




// You are using GCC
#include<stdio.h>
int main(){
    long long int n;
    long int product=1;
    scanf("%lld",&n);
    while(n>0){
        int rem=n%10;
        n=n/10;
        product*=rem;
    }
    printf("%ld",product);
}