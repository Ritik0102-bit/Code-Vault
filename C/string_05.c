// WAP to find out no. of words,spaces and character in a string
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char str[100];
    int sp=0;
    fgets(str,100,stdin);
    str[strcspn(str,"\n")]='\0';
    
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            sp++;
        }
    }

    printf("words : %d\n",sp+1);
    printf("spaces : %d \n",sp);
    printf("characters : %d \n",strlen(str)-sp);
}


// 2nd Approach

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main() {
//     char str[100];
//     int words = 0, spaces = 0, characters = 0;
//     int inWord = 0;

//     fgets(str, 100, stdin);
//     str[strcspn(str, "\n")] = '\0';

//     for (int i = 0; str[i] != '\0'; i++) {
//         if (isspace(str[i])) {
//             spaces++;
//             inWord = 0;
//         } else {
//             characters++;
//             if (!inWord) {
//                 words++;
//                 inWord = 1;
//             }
//         }
//     }

//     printf("Words: %d\n", words);
//     printf("Spaces: %d\n", spaces);
//     printf("Characters: %d\n", characters);
//     return 0;
// }
