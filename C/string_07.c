// anagram of string or not

#include<stdio.h>
#include<string.h>

int main(){
    char str[100],str1[100],temp;
    scanf("%s",str);
    scanf("%s",str1);
    int l=strlen(str);
    int l1=strlen(str1);
    for(int i=0;i<l-1;i++){
        for(int j=0;j<l-i-1;j++){
            if(str[j]>str[j+1]){
                temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
    for(int i=0;i<l1-1;i++){
        for(int j=0;j<l1-i-1;j++){
            if(str1[j]>str1[j+1]){
                temp=str1[j];
                str1[j]=str1[j+1];
                str1[j+1]=temp;
            }
        }
    }

    // strings after sorting
    printf("%s\n",str);
    printf("%s\n",str1);
    int f=1;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=str1[i]){
            f=0;
            break;
        }
    }
    if(strlen(str)==strlen(str1)){
        if(f=1){
        printf("Anagram");
    }
}
    else{
        printf("Not Anagram");
    }
}