#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n>0){
        int rem=n%10;
        cout<< rem;
        n/=10;
    }
}

// OR
// if we want to store that reverse no. into some variable then print in one time

int main(){
    int n;
    cin >> n;
    int reverse=0;
    while(n>0){
        int rem=n%10;
        n/=10;
        reverse=reverse*10+rem;
    }
    cout<< reverse;
}