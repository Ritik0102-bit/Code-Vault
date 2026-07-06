/*
Problem Statement



In a mathematics competition, participants are asked to calculate the double factorial of a given positive integer. 



Write a program that takes the participant's input as a global variable n, computes the double factorial, and prints the result to help them in the competition.



Double Factorial: Product of all positive integers with the same parity down to 1 i.e,

If n is even, n!! is the product of all even integers from n to 1.
If n is odd, n!! is the product of all odd integers from n to 1.
Input format :
The input consists of an integer n.

Output format :
The output prints an integer representing the double factorial of n.



Refer to the sample output for the formatting specifications.

Code constraints :
In the given scenario, the test cases fall under the following constraints:

2 ≤ n ≤ 15

Sample test cases :
Input 1 :
2
Output 1 :
2
Input 2 :
5
Output 2 :
15
*/



// You are using GCC
#include<stdio.h>
int n;
int main(){
    int double_fac=1;
    scanf("%d",&n);
    for(int i=n;i>=1;i-=2){
        double_fac*=i;
    }
    printf("%d",double_fac);
}