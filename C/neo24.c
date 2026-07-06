/*
Problem Statement



Jacob was tasked with writing a program to find the smallest number among three numbers, but he was instructed to write the program using the extern storage class. 



Assist him in accomplishing his task.

Input format :
The input consists of three space-separated integers, a, b and c.

Output format :
The output displays "Smallest number is " followed by the smallest of three numbers.



Refer to the sample output for the formatting specifications.

Code constraints :
In the given scenario, the test cases will fall under the following constraints:

1 ≤ a, b, c ≤ 105

Sample test cases :
Input 1 :
5678 4589 4532
Output 1 :
Smallest number is 4532
Input 2 :
1075 6785 1563
Output 2 :
Smallest number is 1075
*/




// You are using GCC
#include<stdio.h>
// extern void Smallest_number(int,int,int);
void Smallest_number(int a,int b,int c){
    if(a<b && a<c)
    printf("Smallest number is %d",a);
    else if(b<a && b<c)
    printf("Smallest number is %d",b);
    else
    printf("Smallest number is %d",c);
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    Smallest_number(a,b,c);
}