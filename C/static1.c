/*
Problem Statement



Emma is organizing a science exhibition and wants to create displays with a specific number of objects. She needs to ensure the number of objects in each display is a power of 2 for symmetry. 



Write a program to help Emma check if a given number N is a power of 2. 



Example



Input: N = 8

Output: YES

Explanation: 8 is equal to 2 raised to 3 (23 = 8).

Input format :
The input consists of a non-negative integer N.

Output format :
If N is a power of 2, the output is "YES".

If N is not a power of 2, the output is "NO".



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 512

Sample test cases :
Input 1 :
64
Output 1 :
YES
Input 2 :
98
Output 2 :
NO
*/

// You are using GCC
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int x=(n)&(n-1);
    (x==0)?printf("Yes"):printf("No");
}