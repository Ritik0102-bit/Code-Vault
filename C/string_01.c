#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char str[100];
    gets(str); // Read a string from the user
    printf("You entered: %s\n", str); // Print the string entered by the user
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == 'a'){
            str[i] = 'A'; // Replace character 'a' with 'A'
        }
    }
    printf("String after replacing 'a' with 'A': %s\n", str); // Print the string after replacing 'a' with 'A'
    return 0;
}
