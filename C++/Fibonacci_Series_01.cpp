// 2nd Method
// it's a efficient way
// In this method we are not storing each value of the series, we are just storing last two terms

#include<iostream>

using namespace std;

int main(){
    int n;
    cout << "Enter the term you want from fibonacci series: ";
    cin >> n;

    int a=0;
    int b=1;
    int c;
    for(int i=2;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }

    cout << "The " << n << "th term of the fibonacci series is: " << c;
}