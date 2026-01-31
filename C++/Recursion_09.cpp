// In this code we are going to make a function for calculating sum of numbers from 1 to n but with alternate signs using recursion
// for n=5 -->  1-2+3-4+5 = 3

// Test case 1: n=5
// Output : 3
// Test case 1: n=10
// Output : -5


#include<iostream>

using namespace std;

int sum_with_alternate_sign(int n){
    if(n<=0){
        return 0;
    }
    else{
        return ((n%2==0)? -n : n) + sum_with_alternate_sign(n-1);
    }
}

int main(){
    int n;
    cin >> n;

    cout << sum_with_alternate_sign(n);
}