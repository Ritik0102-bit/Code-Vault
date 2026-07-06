/*
Problem Statement



Selva is curious about the sum of even Fibonacci numbers. He wants to write a program that calculates the sum of even Fibonacci numbers up to a given limit. 



Write a program that takes an integer N as input, representing the limit, and calculates the sum of even Fibonacci numbers from 0 to N (inclusive) using the call-by-reference function called evenFibSum. If the limit is less than 2, the result should be 0.

Input format :
The input consists of an integer N, indicating the limit for calculating the sum of even Fibonacci numbers.

Output format :
The output displays an integer representing the sum of all the even Fibonacci numbers from 0 to N (inclusive).



Refer to the sample outputs for formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ N ≤ 50000

Sample test cases :
Input 1 :
12
Output 1 :
10
Input 2 :
243
Output 2 :
188
Input 3 :
1
Output 3 :
0
*/


#include <stdio.h>

// Function to calculate the sum of even Fibonacci numbers up to N
void evenFibSum(int n, int *sum) {
    int a = 0, b = 1, next;

    *sum = 0; // Initialize sum to zero

    while (1) {
        next = a + b; // Generate next Fibonacci number
        if (next > n) // Stop if the next term exceeds N
            break;
        if (next % 2 == 0) // Check if even
            *sum += next;
        
        a = b;
        b = next;
    }
}

int main() {
    int n, sum;
    
    // Read input
    scanf("%d", &n);

    // Handle cases where n < 2
    if (n < 2) {
        printf("0\n");
    } else {
        // Call function with reference to sum
        evenFibSum(n, &sum);
        printf("%d\n", sum);
    }

    return 0;
}