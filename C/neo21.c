/*
Problem Statement



A group seeks a hidden treasure along a trail of even numbers. Write a program using a call-by-reference function to print the sequence of even numbers between a starting and ending point, guiding the adventurers to the treasure.



﻿Function Specifications: void even(int *, int *)

Input format :
The first line of input consists of an integer a, representing the starting point.

The second line consists of an integer b, representing the ending point.

Output format :
The output displays even numbers from a (inclusive) to b (not inclusive) separated by a space.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ a < b ≤ 1000

Sample test cases :
Input 1 :
1
5
Output 1 :
2 4 
Input 2 :
10
30
Output 2 :
10 12 14 16 18 20 22 24 26
*/



// You are using GCC
#include<stdio.h>
void even(int *a,int *b){
    for(int i=*a;i<*b;i++){
        if(i%2==0){
            printf("%d ",i);
        }
    }
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    even(&a,&b);
    return 0;
}