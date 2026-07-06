// WAP to swap the values of two variables without temporary variable

#include<stdio.h>
int main(){
int a,b;
printf("\n Enter the values of a and b:");
scanf("%d%d",&a,&b);
a=a+b;
b=a-b;
a=a-b;
printf("\n(After swapping) Value of a is:%d, and b is:%d",a,b);
return 0;
}