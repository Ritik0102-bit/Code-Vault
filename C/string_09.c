// Write a program to remove duplicate character from the string
// (means the character which are repeating) also the spaces 
// we need to consider uppercase and lowercase of same character as diiferent in the string

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void removeDuplicates(char *str){
    int seen[256]={0};
    int i=0,j=0;
    while(str[i]!='\0'){
        if(seen[str[i]]==0){
            seen[str[i]]=1;
            str[j]=str[i];
            j++;
        }
        i++;
    }
    str[j]='\0';
}

int main(){
    char str[100];
    fgets(str,100,stdin);
    str[strcspn(str,"\n")]='\0';
    removeDuplicates(str);
    printf("%s",str);
    return 0;
}

// Second Approach
// in this uppercase and lowercase are taken as same charcter

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// int main(){
//     int arr[52]={0};
//     char str[100];
//     scanf("%s",str);
//     for(int i=0;i<strlen(str);i++){
//         if(isupper(str[i])){
//             arr[str[i]-'A']++;
//             if(arr[str[i]-'A']==1)
//             printf("%c",str[i]);
//         }
//         if(islower(str[i])){
//             arr[str[i]-'a']++;
//             if(arr[str[i]-'a']==1)
//             printf("%c",str[i]);
//         }
//     }
// }