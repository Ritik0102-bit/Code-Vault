#include<stdio.h>
int main(){
    FILE *fptr;
    fptr=fopen("text.txt","r");  // for reading the file we use "r"

    // for binary files we use "rb" and "wb" for write data

    char ch;
    fscanf(fptr,"%c",&ch);  // used to read character from the file
    printf("%c",ch);
    fscanf(fptr,"%c",&ch);
    printf("%c",ch);
    fscanf(fptr,"%c",&ch);
    printf("%c",ch);
    fscanf(fptr,"%c",&ch);
    printf("%c",ch);
    fscanf(fptr,"%c",&ch);
    printf("%c",ch);
    fclose(fptr);

    // OR we can read with help of fgetc also
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    
    
    // to write into the file
    fptr=fopen("text.txt","w");
    fprintf(fptr,"%c",'M');
    fprintf(fptr,"%c",'a');
    fprintf(fptr,"%c",'n');
    fprintf(fptr,"%c",'g');
    fprintf(fptr,"%c",'o');
    fclose(fptr);

    // OR we can write with the help of fputc also
    fputc('M',fptr);
    fputc('a',fptr);
    fputc('n',fptr);
    fputc('g',fptr);
    fputc('o',fptr);
    

    // to append data into file
    fptr=fopen("text.txt","a");
    fprintf(fptr,"%c",'G');
    fprintf(fptr,"%c",'r');
    fprintf(fptr,"%c",'a');
    fprintf(fptr,"%c",'p');
    fprintf(fptr,"%c",'e');
    fprintf(fptr,"%c",'s');
    fclose(fptr);

}