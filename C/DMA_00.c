// normally in programs the memory is allocated at the time of compile time

// But In Dynamic Memory Allocation we allocate memory during the runtime.

#include<stdio.h>
#include<stdlib.h>

int main() {

    //sizeof function
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(char));


    //Malloc
    // intializes as garbage value
    int *ptr;
    ptr = (int *) malloc(5 * sizeof(int));
    for(int i=0; i<5; i++) {
    scanf("%d", &ptr[i]);
    }
    for(int i=0; i<5; i++) {
    printf("number %d = %d\n", i+1, ptr[i]);
    
    }
    
    free(ptr);
    return 0;
    }