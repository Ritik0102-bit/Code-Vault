#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char str[100];
    gets(str); // Read a string from the user
    printf("You entered: %s\n", str); // Print the string entered by the user
    int count = 0;
    // Count the number of vowels in the string both uppercase and lowercase
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            count++;
        }
    }
    printf("Number of vowels in the string: %d\n", count); // Print the number of vowels in the string
    int length = strlen(str); // Get the length of the string
    printf("Length of the string: %d\n", length); // Print the length of the string
}