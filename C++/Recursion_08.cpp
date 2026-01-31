// In this code we are going to make a function for printing k multiples of a number using recursion

#include<iostream>

using namespace std;

void Multiples_of_k(int num,int k){
    if(k<=0){
        return;
    }
    Multiples_of_k(num,k-1);
    cout << num*k << " ";
}

int main(){
    int num,k;
    cout << "Enter the value of number & K : ";
    cin >> num >> k ;

    Multiples_of_k(num,k);

    return 0;
}