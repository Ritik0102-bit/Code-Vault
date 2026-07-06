//Check Whether the number is Armstrong OR not
#include<stdio.h>
int main(){
    int n,sum=0,n1;
    int rem;
    printf("\n Enter number: ");
    scanf("%d",&n);
    n1=n;
    while(n>0){
        rem=n%10;
        n=n/10;
        sum=sum+(rem*rem*rem);
    }
    if(n1==sum){
        printf("The number is Armstrong number");
    }
    else{
        printf("The number is not Armstrong number");
    }
}