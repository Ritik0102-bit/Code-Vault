//Check Whether the number is Armstrong OR not
#include<stdio.h>
#include<math.h>
int main(){
    int n,sum=0,n1,i=0;
    int rem;
    printf("\n Enter number: ");
    scanf("%d",&n);
    n1=n;
    while(n>0){
        rem=n%10;
        n=n/10;
        i+=1;
    }
    while(n>0){
        rem=n%10;
        n=n/10;
        sum=sum+pow(rem,i);
    }
    if(n1==sum){
        printf("The number is Armstrong number");
    }
    else{
        printf("The number is not Armstrong number");
    }
}