// In this code we are going to make a function for calculating POWER using recursion
// It's a efficient way

#include<iostream>

using namespace std;

int power(int p,int q){
    if(q==0){
        return 1;
    }
    if(q%2==0){
        // if q is even
        int result = power(p,q/2);
        return result * result;
    }
    else{
        // if q is odd
        int result =power(p,(q-1)/2);
        return p * result * result;
    }
}

int main(){
    int res=power(2,3);
    cout << res ;
    return 0;
}