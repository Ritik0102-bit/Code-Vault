#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char ch,str[100],sen[100];
    scanf("%c",&ch);
    scanf("%s",str);
    fgets(sen, 100, stdin);
    sen[strcspn(sen,"\n")]='\0';
    printf("%c\n",ch);
    printf("%s\n",str);
    for(int i=0;sen[i]!='\0';i++){
        printf("%c",sen[i]);
    }
    return 0;
}