/*
Problem Statement



Create a program to assist a fitness tracker. Input the user's current step count (n). 



If n is even, print 'M' for meeting the daily goal, and set the next day's goal to half of n.
If n is odd, print 'A' for almost reaching the goal and set the goal to n minus 1. 


Repeat this until n becomes 1. Write a recursive function called fitness_tracker that performs the above adjustments and prints the achievement status.



For Example, if n=5

For n = 5, it prints 'A'. Since n is odd, it subtracts 1 to get n = 4.
For n = 4, it prints 'M'. Since n is even, it halves n to get n = 2.
For n = 2, it prints 'M'. Since n is even, it halves to reach n = 1, completing the process.
So, the output is AMM.
Input format :
The input consists of an integer n, representing the user's current step count.

Output format :
The output prints 'M' or 'A' based on meeting or almost reaching the daily goal, adjust and display the next day's goal, until 'n' becomes 1.



Refer to the sample output for the formatting specifications.

Code constraints :
In the given scenario, the test cases fall under the following constraints:

5 ≤ n ≤ 50

Sample test cases :
Input 1 :
5
Output 1 :
AMM
Input 2 :
12
Output 2 :
MMAM

*/





// You are using GCC
#include<stdio.h>
void fitness_tracker(int n){
    if(n==1){
        printf("");
    }
    else if(n%2==0){
        printf("M");
        fitness_tracker(n/2);
    }
    else{
        printf("A");
        fitness_tracker(n-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    fitness_tracker(n);
    return 0;
}