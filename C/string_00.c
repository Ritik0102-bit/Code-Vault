// all string functions

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char str1[100], str2[100];
    printf("Enter first string: ");
    gets(str1); // Read first string from the user
    printf("Enter second string: ");
    gets(str2); // Read second string from the user

    // String length
    printf("Length of first string: %d\n", strlen(str1)); // Print length of first string
    printf("Length of second string: %d\n", strlen(str2)); // Print length of second string

    // String copy
    strcpy(str2, str1); // Copy str1 to str2
    printf("After copying, second string: %s\n", str2); // Print second string after copying

    // String concatenation
    strcat(str1, str2); // Concatenate str2 to str1
    printf("After concatenation, first string: %s\n", str1); // Print first string after concatenation

    // String comparison
    int cmp = strcmp(str1, str2); // Compare str1 and str2
    if(cmp == 0){
        printf("Strings are equal\n"); // Strings are equal
    } else if (cmp < 0){
        printf("First string is less than second string\n"); // First string is less than second string
    } else {
        printf("First string is greater than second string\n"); // First string is greater than second string
    }
    
    
    strrev(str1); // Reverse the string
    printf("Reversed first string: %s\n", str1); // Print reversed first string
    
    strlwr(str1); // Convert string to lowercase
    printf("Lowercase first string: %s\n", str1); // Print lowercase first string
    
    strupr(str1); // Convert string to uppercase
    printf("Uppercase first string: %s\n", str1); // Print uppercase first string
    
    strset(str1, 'a'); // Set all characters in the string to 'a'
    printf("String after setting all characters to 'a': %s\n", str1); // Print string after setting all characters to 'a'
    
    strnset(str1, 'b', 5); // Set first 5 characters in the string to 'b'
    printf("String after setting first 5 characters to 'b': %s\n", str1); // Print string after setting first 5 characters to 'b'
    
    strncat(str1, str2, 5); // Concatenate first 5 characters of str2 to str1
    printf("String after concatenating first 5 characters of second string: %s\n", str1); // Print string after concatenating first 5 characters of second string

    strchr(str1, 'a'); // Find first occurrence of 'a' in str1
    printf("First occurrence of 'a' in first string: %s\n", strchr(str1, 'a')); // Print first occurrence of 'a' in first string
    
    strrchr(str1, 'a'); // Find last occurrence of 'a' in str1
    printf("Last occurrence of 'a' in first string: %s\n", strrchr(str1, 'a')); // Print last occurrence of 'a' in first string
    
    printf("Integer value of first string: %d\n", atoi(str1)); // Print integer value of first string

    printf("String value of first string after conversion: %s\n", itoa(atoi(str1), str1, 10)); // Print string value of first string after conversion
    
    printf("Double value of first string: %lf\n", atof(str1)); // Print double value of first string
    
    return 0;
}