/*
Problem Statement



Regis has a character in mind that he wants to convert to its ASCII value. After obtaining the ASCII value, he wants to modify the ASCII value into one of the following:



Add 32 if the ASCII value falls between 65 and 90 (inclusive)
Subtract 32 if the ASCII value is between 97 and 122 (inclusive)
Print the original value for other cases


Write a program to get a character input from the user and print its corresponding ASCII value.

Input format :
The input consists of the character value c.

Output format :
The output displays "ASCII Value: " followed by the integer value after performing the required operation on the ASCII value of c.



Refer to the sample output for the formatting specifications.

Code constraints :
In the given scenario, the test cases fall under the following constraints:

Valid ASCII characters must be given as input.

Sample test cases :
Input 1 :
A
Output 1 :
ASCII Value: 97
Input 2 :
~
Output 2 :
ASCII Value: 126
Input 3 :
z
Output 3 :
ASCII Value: 90
Input 4 :
3
Output 4 :
ASCII Value: 51
*/



#include <stdio.h>

int main() {
    char c;
    int ascii_value, modified_value;

    // Taking character input from the user
    scanf("%c", &c);
    
    // Getting the ASCII value of the character
    ascii_value = (int)c;

    // Modifying the ASCII value based on conditions
    if (ascii_value >= 65 && ascii_value <= 90) {
        modified_value = ascii_value + 32;
    } else if (ascii_value >= 97 && ascii_value <= 122) {
        modified_value = ascii_value - 32;
    } else {
        modified_value = ascii_value;
    }

    // Printing the output
    printf("ASCII Value: %d\n", modified_value);

    return 0;
}