/*
Problem Statement



Alex is diving into a mathematical challenge to uncover the largest prime factor of a positive integer. Given an integer n (long long int), write a program to determine its greatest prime divisor. 



Display the result to assist Alex in his exploration.

Input format :
The input consists of a long long integer n.

Output format :
The output prints the greatest prime divisor as a long long integer.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the given test cases fall under the following constraints:

1 ≤ n ≤ 106

Sample test cases :
Input 1 :
100
Output 1 :
5
Input 2 :
35
Output 2 :
7
*/

#include <stdio.h>
int main() { 
int n,i=2;
scanf("%d",&n);
while(n!=1)
{
    if(n%i==0)
    {
        n=n/i;
    }
    else 
    i++;
}
printf("%d",i);
   return 0;
}
