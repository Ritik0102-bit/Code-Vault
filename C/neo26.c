/*
Problem Statement



Ravi is designing a program to track a counter that remembers its value across 3 function calls. He decides to use a static variable in the display() function, which increments the counter by 3 each time the function is called. 



Write a program where the user inputs an initial value for the counter during each call, and the static variable retains and updates its value, printing the result after each update.

Input format :
The input consists of an integer n.

Output format :
The output prints the result after each update.



Refer to the sample output for the formatting specifications.

Code constraints :
In the given scenario, the test cases fall under the following constraints:

-100 ≤ n ≤ 100

Sample test cases :
Input 1 :
-20
Output 1 :
-17
-14
-11
Input 2 :
32
Output 2 :
35
38
41
*/



// You are using GCC
#include<stdio.h>
static int n;
int main(){
    scanf("%d",&n);
    printf("%d",n+3);
    n+=3;
    printf("%d",n+3);
    n+=3;
    printf("%d",n+3);
    n+=3;
}