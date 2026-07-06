#include<stdio.h>
int main(){
    int n1,n2,n3,n4;
    printf("enter marks: ");
    scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
    float n=n1+n2+n3+n4/4;
    if(n>90){
        printf("Your Garde is A");
    }
    else if(n<90 && n>=80){
        printf("Your Garde is B");
    }
    else if(n>=70 && n<80){
        printf("Your Garde is C");
    }
    else if(n>=40 && n<70){
        printf("Your Garde is D");
    }
    else{
        printf("You are Fail");
    }
}

