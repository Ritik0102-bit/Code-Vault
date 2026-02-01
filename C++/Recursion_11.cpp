// In this code we are going to make a function for checking whether a number is ARMSTRONG or not using recursion

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


int Check_Armstrong(int n,int p){
    if(n==0){
        return 0;
    }
    return ((power(n%10,p)) + (Check_Armstrong(n/10,p)));
}


int main(){
    int n;
    cout << "Enter the Number : ";
    cin >> n;

    int temp=n;
    int no_of_digits=0;
    while(temp>0){
        temp=temp/10;
        no_of_digits++;
    }
    
    if(Check_Armstrong(n,no_of_digits)==n){
        cout << "The Number is a Armstrong Number ";
    }
    else{
        cout << "The Number is not a Armstrong Number ";
    }

    return 0;
}