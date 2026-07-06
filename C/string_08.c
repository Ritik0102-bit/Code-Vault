// write a program to find substring position in a string

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
    char str[100];
    char str2[100];
    scanf("%s",str);
    scanf("%s",str2);
    int i,j;
    for(i=0;i<strlen(str);i++){
        str[i]=tolower(str[i]);
    }
    for(i=0;i<strlen(str2);i++){
        str2[i]=tolower(str2[i]);
    }
    for(i=0;i<strlen(str)-strlen(str2)+1;i++){
        char sub[100];
        for(j=0;j<strlen(str2);j++){
            sub[j]=str[i+j];
        }
        sub[j]='\0';
        if(!strcmp(sub,str2))
        printf("found at: %d\n",i);
    }
}