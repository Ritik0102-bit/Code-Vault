/*
Problem Statement



Arun wants to implement a function to check whether an integer n is an Armstrong number or not using a call-by-reference function. Assist him in completing the program.



An Armstrong number is a number that is equal to the sum of its digits each raised to the power of the number of digits.



Function Specifications: void checkArmstrong(int *n)

Input format :
The input consists of an integer n.

Output format :
If n is an Armstrong number, the output prints "Armstrong number".

If n is not an Armstrong number, the output prints "Not an Armstrong number".



Refer to the sample output for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ n ≤ 1000

Sample test cases :
Input 1 :
153
Output 1 :
Armstrong number
Input 2 :
29
Output 2 :
Not an Armstrong number
*/


#include<stdio.h>
// You are using GCC
#include<math.h>
void checkArmstrong(int *n){
    int temp= *n;
    int temp2=*n;
    int digit=0,sum=0;
    while(temp>0){
        temp/=10;
        digit++;
    }
    while(temp2>0){
        int rem=temp2%10;
        temp2/=10;
        sum+=pow(rem,digit);
    }
    if(*n==sum){
        printf("Armstrong number");
    }
    else{
        printf("Not an Armstrong number");
    }
}


int main() {
    int n;
    scanf("%d", &n);
    checkArmstrong(&n);
    return 0;
}