// hand shake n=2 op=1
// n=5 op=10

// n C r => permutation and combination formula
// n C r => n!/(n-r)! * r!


#include<stdio.h>
int fact(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}
int main(){
    int n;
    scanf("%d",&n);
    int n1=fact(n);
    int n2=fact(n-2);
    printf("%d",n1/(n2*2));
    return 0;
}


