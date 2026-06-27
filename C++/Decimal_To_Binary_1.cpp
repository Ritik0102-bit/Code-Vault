#include<iostream>

using namespace std;

string decimal_to_binary(int n){
    if(n==0){
        return "0";
    }

    string binary="";

    while(n>0){
        binary=(n%2==0 ? "0" : "1") + binary;
        n/=2;
    }

    return binary;
}

int main(){
    int n;
    cin>>n;

    string Binary=decimal_to_binary(n);

    cout << Binary;
    return 0;
}