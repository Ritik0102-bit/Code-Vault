// Problem Statement



// Anu is tasked with developing a program that continuously accepts positive integers as input. For each input, the program should calculate and display its square and cube in a concise format. This process should continue until the input is 0.

// Input format :
// The input consists of multiple positive integers separated by spaces.

// The program will terminate the process when the number 0 is entered. The number 0 should not be processed.

// Output format :
// For each positive integer n, the program should print the following on separate lines:

// "Square of n is" followed by the squared value of the given number.
// "Cube of n is" followed by the cube value of the given number.


// Refer to the sample output for formatting specifications.

// Code constraints :
// 0 ≤ n ≤ 100

// Sample test cases :
// Input 1 :
// 2 0
// Output 1 :
// Square of 2 is 4
// Cube of 2 is 8
// Input 2 :
// 2 3 5 4 8 0
// Output 2 :
// Square of 2 is 4
// Cube of 2 is 8
// Square of 3 is 9
// Cube of 3 is 27
// Square of 5 is 25
// Cube of 5 is 125
// Square of 4 is 16
// Cube of 4 is 64
// Square of 8 is 64
// Cube of 8 is 512



// You are using GCC
#include<stdio.h>
int main(){
    int i;
    while(1){
        scanf("%d",&i);
        if(i==0)
        break;
        printf("Square of %d is %d \n",i,i*i);
        printf("Cube of %d is %d",i,i*i*i);
    }
}