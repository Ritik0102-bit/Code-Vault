#include<iostream>

using namespace std;

// 1st Approach for prime number
bool isprime(int n){
    for(int i=2;i<n-1;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

// 2nd Approach for prime number
bool isprime2(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>> n;
    if(isprime(n)){
        cout<< n<< " is a prime number."<<endl;
    }
    else{
        cout<< n << " is not a prime number."<< endl;
    }
    if(isprime2(n)){
        cout<< n<< " is a prime number."<<endl;
    }
    else{
        cout<< n << " is not a prime number."<< endl;
    }
}