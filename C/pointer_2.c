#include<stdio.h>
int main(){
    int n=100,*ptr;
    ptr=NULL; // null pointer
    printf("%d",*ptr);
    void *ptr1; // void pointer
    printf("%d",*(int*)ptr1); // we need to do typecasting to print void pointer
    int *ptr2; // wild pointer
    printf("%d",*ptr2);
    return 0;
}