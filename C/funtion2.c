#include<stdio.h>
#include<math.h>
void cube(int);
int main(){
    int x;
    scanf("%d",&x);
    printf("Value of x before cube: %d",x);
    cube(x);
    printf("Value of x after cube: %d",x);
}
void cube(int n){
    int cube=pow(n,3);
    printf("Cube of %d is: %d",n,cube);
}