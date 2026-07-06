#include<stdio.h>
void greatest(int,int,int); // this is a function prototype
void factorial(int);
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    greatest(a,b,c);
    factorial(5);
}
// This is function defination
void greatest(int a,int b,int c){
    if(a>b && a>c)
    printf("%d",a);
    else if(b>c && b>a)
    printf("%d",b);
    else
    printf("%d",c);
}
void factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    printf("\n%d",fact);
}