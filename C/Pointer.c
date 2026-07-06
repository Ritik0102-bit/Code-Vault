#include<stdio.h>
int main(){
    int n,fact=1;
    scanf("%d",&n);
    int *ptr,*factorial;
    ptr=&n;
    factorial=&fact;
    for(int i=*ptr;i>0;i--){
        *factorial*=i;
    }
    printf("%d",*factorial);
    return 0;
}