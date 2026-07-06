/*
Problem Statement



Tony is exploring functions and needs your help. Write a program to assist Tony where he inputs an integer N. The program should display the factors of N and count how many digits N has. 



Help him with the program using call-by-reference.



Function Specifications:

To display factors - void factors(int ); 
To display digits - int count_digits(int *);
Input format :
The input consists of an integer N.

Output format :
The first line of output prints "Factors: " followed by the factors of N, separated by a space.

The second line prints "Total digits: " followed by the total digits of N.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases will fall under the following constraints:

3 ≤ N ≤ 1000

Sample test cases :
Input 1 :
99
Output 1 :
Factors: 1 3 9 11 33 99 
Total digits: 2
Input 2 :
458
Output 2 :
Factors: 1 2 229 458 
Total digits: 3
*/




// You are using GCC
#include<stdio.h>
void factors(int n){
    printf("Factors: ");
    for(int i=1;i<=n;i++){
        if(n%i==0)
        printf("%d ",i);
    }
}
int count_digits(int *n){
    printf("\nTotal digits: ");
    int count=0;
    while(*n>0){
        count++;
        *n/=10;
    }
    printf("%d",count);
    return 0;
}
int main(){
    int N;
    scanf("%d",&N);
    factors(N);
    count_digits(&N);
    return 0;
}