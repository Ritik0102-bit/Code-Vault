/*
Problem Statement



Prema is fascinated by number conversions and wants to build a program to convert decimal numbers to octal numbers. She needs your help to write the program using recursion.



Write a program to help Prema convert a given decimal number to its octal representation.



Example



Input:

200

Output:

310

Explanation:

If the decimal number 200 has to be converted to octal,

200 / 8 = 25, remainder = 0

25 / 8 = 3, remainder = 1

3 / 8 = 0, remainder = 3

The equivalent octal number of the decimal number 200 is 310.



Function Specifications: int decimalToOctal(int)

Input format :
The input is an integer, representing the decimal number that Prema wants to convert to octal.

Output format :
The output prints a single integer, which represents the octal representation of the given decimal number.



Refer to the sample outputs for the formatting specifications.

Code constraints :
In the given scenario, the test cases will fall under the following constraints:

1 ≤ decimal ≤ 106

Sample test cases :
Input 1 :
25
Output 1 :
31
Input 2 :
200
Output 2 :
310
*/




// You are using GCC
#include<stdio.h>
void decimalToOctal(int n){
    if(n==0){
        return;
    }
    decimalToOctal(n/8);
    printf("%d",n%8);
}
int main(){
    int n;
    scanf("%d",&n);
    decimalToOctal(n);
}