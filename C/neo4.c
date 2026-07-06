// Problem Statement

//Factorial of a number

// Imagine you are in a top-secret laboratory, working on an experiment that involves rapidly multiplying numbers together. The lab's supercomputer is down, so it is up to you to write a program to calculate factorials manually. 



// Write a program that takes a positive integer as input and calculates its factorial using a for loop. The factorial of a number is the product of all positive integers up to that number.



// Example:

// Sample Input:

// 5

// Sample Output:

// 120

// Explanation:

// The factorial of a number is calculated by multiplying all positive integers up to that number. In this case, the input is 5. The factorial of 5 (denoted as 5!) is calculated as follows:

// 5! = 5 × 4 × 3 × 2 × 1 = 120

// So, the output is 120.

// Input format :
// The input consists of a positive integer n, representing the number for which the factorial needs to be calculated.

// Output format :
// The output prints an integer which is the factorial of n.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// Sample test cases :
// Input 1 :
// 5
// Output 1 :
// 120
// Input 2 :
// 1
// Output 2 :
// 1
// Input 3 :
// 10
// Output 3 :
// 3628800


// You are using GCC
#include<stdio.h>
int main(){
    int n,fac=1;
    scanf("%d",&n);
    for(int i=n;i>0;i--){
        fac*=i;
    }
    printf("%d",fac);
}