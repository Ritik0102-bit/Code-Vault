// WAP to swap the values of two integers with temporary(or third variable) variable
//Note: Here value overwriting has been performed using assignment, so a variable can hold only one value at one time

#include<stdio.h>
int main()
{
int a,b,temp;
printf("\n Enter the values of a and b:");
scanf("%d%d",&a,&b);   
temp=a;   
a=b;   
b=temp;  
printf("\n(After swapping) Value of a is:%d, and b is:%d",a,b);
return 0;
}
