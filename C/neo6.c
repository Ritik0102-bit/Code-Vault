// Problem Statement



// Alice, an avid coder, utilizes the goto statement in her program. When she receives an input, if it's even, she employs goto to print its factors. Otherwise, she uses goto to display the next number of it. 



// Write a program to achieve Alice's task.

// Input format :
// The input line consists of a single integer n, representing the number.

// Output format :
// If n is even:

// The first line displays "Even".
// The second line displays "Factors: " followed by the factors of n, separated by a space.


// If n is odd:

// The first line displays "Odd".
// The second line displays "Next number: " followed by the next number of n.


// Refer to the sample output for the formatting specifications.

// Code constraints :
// In the given scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 100

// Sample test cases :
// Input 1 :
// 1
// Output 1 :
// Odd
// Next number: 2
// Input 2 :
// 100
// Output 2 :
// Even
// Factors: 1 2 4 5 10 20 25 50 100 
// Input 3 :
// 52
// Output 3 :
// Even
// Factors: 1 2 4 13 26 52




// You are using GCC
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n%2==0)
    goto factors;
    else
    goto next;
    next:
    printf("Odd \n");
    printf("Next number: %d",n+1);
    return 0;
    factors:
    printf("Even \n");
    printf("Factors: ");
    for(int i=1;i<=n;i++){
        if(n%i==0)
        printf("%d",i);
    }
    return 0;
}