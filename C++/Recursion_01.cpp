// In this code we are going to make a function for calculating power using recursion

#include<iostream>

using namespace std;

int power(int p,int q){
    if(q==0){
        return 1;
    }
    else{
        return p * power(p,q-1);
    }
}

int main(){
    int res=power(2,3);
    cout << res ;
    return 0;
}