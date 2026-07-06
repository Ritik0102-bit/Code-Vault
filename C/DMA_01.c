#include<stdio.h>
#include<stdlib.h>

int main(){
    //Calloc
    // Initializes as zero
    int *ptr;
    int *ptr = (int *) calloc(5, sizeof(int));
    for(int i=0; i<5; i++) {
    printf("number %d = %d\n", i+1, ptr[i]);
    }

    //free
    free(ptr);
}