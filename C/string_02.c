// This program checks if a string is a palindrome or not. A palindrome is a string that reads the same backward as forward.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str); // Read a string from the user
    printf("You entered: %s\n", str); // Print the string entered by the user
    int length = strlen(str); // Get the length of the string
    int isPalindrome = 1; // Flag to check if the string is a palindrome
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            isPalindrome = 0; // Set flag to 0 if characters don't match
            break;
        }
    }
    if (isPalindrome) {
        printf("The string is a palindrome.\n"); // Print if the string is a palindrome
    } else {
        printf("The string is not a palindrome.\n"); // Print if the string is not a palindrome
    }
    return 0;
}
