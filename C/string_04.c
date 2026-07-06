// WAP to compare two strings without using inbuilt functions
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
    char str1[100], str2[100];
    printf("Enter first string: ");
    gets(str1); // Read first string from the user
    printf("Enter second string: ");
    gets(str2); // Read second string from the user

    int len1=strlen(str1);
    int len2=strlen(str2);
    int len,flag=0,i=0;
    if(len1>len2){
        len=len1;
    }
    else{
        len=len2;
    }
    while(i<len){
        if(str1[i]==str2[i]){
            i++;
        }
        else if(str1[i]>str2[i]){
            flag=1;
            break;
        }
        else{
            flag=-1;
            break;
        }
    }
    if(flag==0){
        printf("string are same");
    }
    else if(flag==1){
        printf("string1 is greater than string2");
    }
    else{
        printf("string2 is greater than string1");
    }
}