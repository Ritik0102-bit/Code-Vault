// The Tribonacci sequence is a variant of the Fibonacci sequence, where each term is the sum of the previous three terms. 
// The sequence starts with three predefined values.

// Given the first three terms of the sequence, calculate the n-th term.

// a(n) = a(n-1) + a(n-2) + a(n-3)

// with a(0) = a(1) = 0, a(2) = 1

// Given an integer n, print the entire Tribonacci sequence up to the n-th term First few numbers in the Tribonacci Sequence are
//  0, 0,1, 1, 2, 4, 7, 13, 24, 44, 81

#include<iostream>

using namespace std;

int trib(int n){
    if(n<=2){
        return 0;
    }
    else if(n==3){
        return 1;
    }
    else{
        return trib(n-1)+trib(n-2)+trib(n-3);
    }
}
int main(){
    int n;
    cin >> n;
    cout << trib(n);
}