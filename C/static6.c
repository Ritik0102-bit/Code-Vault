/*
Problem Statement



Alex is developing a fitness application that utilizes a Collatz-like sequence to gamify step goals. The program employs a static storage specifier. Implement a function collatzSequence(int num), which calculates and displays the sequence for a given number of steps. 



The sequence is generated based on even and odd rules.

If n is even, then n = n / 2.
If n is odd, then n = 3*n + 1.
Repeat the above steps, until it becomes 1.


Example



Input:

3

Output:

3 10 5 16 8 4 2 1 

Explanation:

The input of 3, and the Collatz sequence unfold as follows: 3 is odd, so it becomes 3 * 3 + 1 = 10. Then, 10 is even, halving to 5, and the sequence continues 16, 8, 4, 2, 1.

Input format :
The input consists of a positive integer n.

Output format :
The output should display the Collatz sequence, separated by space, starting from the entered number.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases will fall under the following constraints:

1 ≤ n ≤ 100

Sample test cases :
Input 1 :
7
Output 1 :
7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1 
Input 2 :
4
Output 2 :
4 2 1 
*/



// You are using GCC
#include<stdio.h>
void collatzSequence(int n1){
    static int n=n1;
    while(n!=1){
        if(n%2==0){
            printf("%d",n);
            n=n/2;
        }
        else if(n%2!=0){
            printf("%d",n);
            n=3*n+1;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    collatzSequence(n);
    printf("1");
    return 0;
}