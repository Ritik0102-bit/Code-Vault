/*
Problem Statement



Drake is working on a program that converts an integer to both binary and hexadecimal representations. 



Write a program that prints the binary representation of the integer without leading zeros and its hexadecimal representation.

Input format :
The first line of input consists of an integer value 'n', representing the user input.

Output format :
The first line of output displays "Binary: " followed by the binary representation without leading zeros.

The second line of output displays "Hexadecimal: " followed by the hexadecimal representation.



Refer to the sample output for the formatting specifications.

Code constraints :
In this scenario, the test cases fall under the following constraints:

1 ≤ n ≤ 100

Sample test cases :
Input 1 :
3
Output 1 :
Binary: 11
Hexadecimal: 3
Input 2 :
10
Output 2 :
Binary: 1010
Hexadecimal: A
Input 3 :
18
Output 3 :
Binary: 10010
Hexadecimal: 12
*/



#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    // Printing Binary Representation Without Leading Zeros
    printf("Binary: ");
    int started = 0; // Flag to skip leading zeros

    for (int i = 31; i >= 0; i--) {
        if ((n >> i) & 1) {
            started = 1; // Start printing when first 1 is encountered
        }
        if (started) {
            printf("%d", (n >> i) & 1);
        }
    }
    if (!started) {
        printf("0"); // If n is 0, print a single zero
    }

    // Printing Hexadecimal Representation
    printf("\nHexadecimal: %X\n", n);

    return 0;
}