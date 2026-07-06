#include<stdio.h>
#include<stdlib.h>

int main() {
    
    // Realloc
    // Used to reallocate the memory
    int *ptr;
    ptr = (int *) malloc(5 * sizeof(int));
    for(int i=0; i<5; i++) {
    scanf("%d", &ptr[i]);
    }
    for(int i=0; i<5; i++) {
    printf("number %d = %d\n", i+1, ptr[i]);
    }

    ptr=realloc(ptr,8);
    for(int i=0; i<8; i++) {
        scanf("%d", &ptr[i]);
    }
    for(int i=0; i<8; i++) {
    printf("number %d = %d\n", i+1, ptr[i]);
    }
    free(ptr);
    return 0;
    }