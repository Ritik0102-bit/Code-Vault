/*
Problem Statement



Vasu wants to generate a sequence of numbers from a given point up to 10.



Write a program to assist Vasu that takes an integer N as input and generates the sequence from N to 10 (inclusive) using a function called count(). 

Input format :
The input consists of an integer N, representing the starting point.

Output format :
The output prints the sequence of numbers starting from N to 10 (inclusive), separated by a space.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 10

Sample test cases :
Input 1 :
1
Output 1 :
1 2 3 4 5 6 7 8 9 10 
Input 2 :
5
Output 2 :
5 6 7 8 9 10 
Input 3 :
10
Output 3 :
10 
*/



// You are using GCC
#include<stdio.h>
int count(int n){
    for(n;n<=10;n++){
        printf("%d ",n);
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    count(n);
    return 0;
}