/*Problem Statement



Sheela and Balu are discussing automorphic numbers, a special type where the square of a number ends with the same digits as the original number. Balu is tasked with creating a program to determine if a given number is automorphic using the function isAutomorphic(). 



Help him achieve this.

Input format :
The input consists of an integer n, representing the number that Balu needs to check for being an automorphic number.

Output format :
If n is an automorphic number, the output prints "The number is an automorphic."

If n is not an automorphic number, the output prints "The number is NOT an automorphic."



Refer to the sample output for the formatting specifications.

Code constraints :
In the given scenario, the test cases will fall under the following constraints:

1 ≤ n ≤ 100

Sample test cases :
Input 1 :
5
Output 1 :
The number is an automorphic.
Input 2 :
7
Output 2 :
The number is NOT an automorphic

*/




// You are using GCC
#include<stdio.h>
void isAutomorphic(int n){
    int n1=n;
    int original=n1%10;
    int sqr=n*n;
    int square=sqr%10;
if(square==original){
    printf("The number is an automorphic.");
}
else{
    printf("The number is NOT an automorphic.");
}
}
int main(){
    int n;
    scanf("%d",&n);
    isAutomorphic(n);
}