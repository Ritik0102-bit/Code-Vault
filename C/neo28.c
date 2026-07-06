/*
Problem Statement



Abigail is fascinated by the occurrences of the digit '3' in numbers. She has a keen interest in counting the number of times the digit '3' appears in a range of numbers. She wants to know the total count of occurrences from the number 2 to the given number n.



Write a program that takes the input n, calculates, and displays the total count of occurrences of the digit '3' in the range from 2 to n.



Function Specifications:

int count_3s(int n) - Counts and returns the number of occurrences of the digit '3' in a given integer.
int count_in_range(int n) - Calculates and returns the total count of the digit '3' in all numbers from 2 to n.
Input format :
The input consists of an integer n, representing the upper limit of the range for counting 3s.

Output format :
The output displays the total count of the digit '3' from 2 to n (inclusive) as an integer.



Refer to the sample output for the formatting specifications.

Code constraints :
The given test cases will fall under the following constraints:

3 ≤ n ≤ 1500

Sample test cases :
Input 1 :
4
Output 1 :
1
Input 2 :
25
Output 2 :
3
Input 3 :
1500
Output 3 :
500

*/

#include <stdio.h>

// Function to count occurrences of digit '3' in a single number
int count_3s(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 10 == 3) { // Check if last digit is 3
            count++;
        }
        n /= 10; // Remove the last digit
    }
    return count;
}

// Function to count occurrences of digit '3' in numbers from 2 to n
int count_in_range(int n) {
    int total_count = 0;
    for (int i = 2; i <= n; i++) {
        total_count += count_3s(i); // Count '3's in each number
    }
    return total_count;
}

int main() {
    int n;
    scanf("%d", &n); // Read input
    printf("%d\n", count_in_range(n)); // Print result
    return 0;
}