/*
Problem Statement



John wants to create a program that can print the multiplication table of any given number. 



Help John write a program that takes a number from the user and prints its multiplication table from 1 to 10 using a do-while loop.

Input format :
The input consists of an integer n.

Output format :
The output prints the multiplication table for the given number up to 10 in separate lines.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ n ≤ 100

Sample test cases :
Input 1 :
6
Output 1 :
6 x 1 = 6
6 x 2 = 12
6 x 3 = 18
6 x 4 = 24
6 x 5 = 30
6 x 6 = 36
6 x 7 = 42
6 x 8 = 48
6 x 9 = 54
6 x 10 = 60
Input 2 :
19
Output 2 :
19 x 1 = 19
19 x 2 = 38
19 x 3 = 57
19 x 4 = 76
19 x 5 = 95
19 x 6 = 114
19 x 7 = 133
19 x 8 = 152
19 x 9 = 171
19 x 10 = 190
*/


// You are using GCC
#include<stdio.h>
int main()
{
    int n,i=1;
    scanf("%d",&n);
    do
    {
       
        printf("%d x %d=%d\n",n,i,n*i);
        i++;
    }
    while(i<=10);
}