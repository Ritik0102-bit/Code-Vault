//Problem Statement

//Binary conversion of the number


// Imagine you are tasked with developing a simple utility to convert decimal numbers to binary. The program should efficiently determine and print the binary representation of a given decimal input in the correct order using a do-while loop.

// Input format :
// The input consists of a positive integer n, representing the decimal number to be converted to binary.

// Output format :
// The output prints the binary form of the given integer.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 103

// Sample test cases :
// Input 1 :
// 12
// Output 1 :
// 1100
// Input 2 :
// 1000
// Output 2 :
// 1111101000
// Input 3 :
// 1
// Output 3 :
// 1 



#include<stdio.h>
int main(){
    int n,binary[32],i=0;
    scanf("%d",&n);
    do{binary[i]=n%2;
    n=n/2;
    i++;
    }while(n>0);
    for(int j=i-1;j>=0;j--){
        printf("%d",binary[j]);
    }
}