// Problem Statement



// Anna is working on a program to find common factors of two unsigned integers. Design a program that:

// Takes two unsigned integers: n1 and n2, as input.
// Identifies and prints all common factors of these numbers.


// For example, Let us take two numbers 24 and 36. The factors of 24 are 1, 2, 3, 4, 6, 8, 12, 24. The factors of 36 are 1, 2, 3, 4, 6, 9,  12, 36. The common factors of 24 & 36 are 1,2,3,4,6,12 

// Ensure the program accurately identifies common factors, providing correct results for various inputs.

// Input format :
// The input consists of two unsigned integers n1 and n2 separated by a space.

// Output format :
// The output prints the common factors of n1 and n2, separated by a space.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the given test cases fall under the following constraints:

// 1 ≤ n1, n2 ≤ 100

// Sample test cases :
// Input 1 :
// 24 36
// Output 1 :
// 1 2 3 4 6 12 
// Input 2 :
// 2 2 
// Output 2 :
// 1 2 
// Input 3 :
// 100 100
// Output 3 :
// 1 2 4 5 10 20 25 50 100 




// You are using GCC
#include<stdio.h>
int main(){
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    for(int i=1;i<=n1;i++){
        if(n1%i==0 && n2%i==0)
        printf("%d ",i);
    }
}