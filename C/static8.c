/*
Problem Statement



Given a number N, calculate the prime numbers up to N. Write the call-by-value function isPrime which takes an integer N as an input parameter and returns the list of prime numbers less than or equal to N.



Examples



Input: N = 10

Output: 2 3 5 7

Explanation: Prime numbers less than or equal to 10 are 2, 3, 5 and 7.



Input: N = 35

Output: 2 3 5 7 11 13 17 19 23 29 31

Explanation: Prime numbers less than or equal to 35 are 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 and 31.

Input format :
The input consists of a positive integer N.

Output format :
The output prints space-separated integers representing the list of prime numbers less than or equal to N.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

2 ≤ N ≤ 104

Sample test cases :
Input 1 :
13
Output 1 :
2 3 5 7 11 13 
Input 2 :
50
Output 2 :
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 
*/




// You are using GCC
#include<stdio.h>
int isPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
            }
        }
    return 1;
}
int main(){
    int x;
    scanf("%d",&x);
    for(int i=2;i<=x;i++){
        if(isPrime(i)==1){
            printf("%d ",i);
        }
    }
    
}