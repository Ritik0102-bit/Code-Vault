/*
Problem Statement



Merlin is working on a calendar application that requires a leap-year verification feature for accurate event scheduling. Users input a year, and her program determines whether it's a leap year or not, aiding in precise calendar calculations. 



Help her write a program to determine if the given year is a leap year or not by using only switch statements and operators.

Input format :
The input consists of an integer representing the year.

Output format :
The output prints whether the given year is a leap year or not.



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1900 ≤ input year ≤ 2100

Sample test cases :
Input 1 :
2012
Output 1 :
2012 is a leap year.
Input 2 :
2010
Output 2 :
2010 is not a leap year.

*/



#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int y=(x%4==0 && x%100!=0 || x%400==0);
    switch(y)
    {
        case 1:printf("%d is a leap year.",x);
        break;
        default:printf("%d is not a leap year.",x);
    }
    
    
}