#include<stdio.h>
int main(){
    FILE *fptr;
    fptr = fopen("text.txt", "r");
    char ch;
    ch = fgetc(fptr);
    // when we are reading file with fgetc , it returns EOF at the end of file.
    while(ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fptr);
    }
    printf("\n");
    fclose(fptr);
    return 0;
}