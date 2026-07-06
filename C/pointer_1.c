#include<stdio.h>
int main(){
    int a=100,b=200;
    int *p1,*p2;
    p1=&a;
    p2=&b;
    printf("memory address p1 pointing to = %u \n",p1);
    printf("memory address p2 pointing to = %u \n",p2);
    printf("memory address p1 pointing to after pre increment = %u \n",++p1);
    printf("memory address p1 pointing to after post increment = %u \n",p1++);
    printf("Current address of pointer %d \n",p1);
    p1+=2;
    printf("adding +2 to pointer = %u \n",p1);
    int res=p1-p2;
    printf("pointer far from each other = %d \n",res);
    p2=p1;
    printf("memory address p1 pointing to = %u \n",p1);
    printf("memory address p2 pointing to = %u \n",p2);
    return 0;
}