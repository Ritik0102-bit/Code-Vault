/*
Problem Statement



Induja is intrigued by the idea of calculating the product of all odd numbers from 1 to N (inclusive). She needs a program that can quickly perform this multiplication for any given integer. 



Write a program to help her that takes an integer as input, calculates the product of odd numbers from 1 to N using a function called OddMultiply(), and then prints the result.

Input format :
The input consists of a positive integer, N.

Output format :
The output prints the result of the product of odd numbers between 1 and N (inclusive).



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

2 ≤ N ≤ 15

Sample test cases :
Input 1 :
5
Output 1 :
15
Input 2 :
8
Output 2 :
105
*/

#include<stdio.h>
// You are using GCC
int OddMultiply(){
    int n;
    long long int product=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            product*=i;
        }
    }
    return product;
}
int main() {
    int oddMultiplication = OddMultiply();
    printf("%lld\n", oddMultiplication);

    return 0;
}