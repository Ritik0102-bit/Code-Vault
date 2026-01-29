// In this code we are going to calculate the sum of each digits in a number (Recursively)

#include<iostream>

using namespace std;

int Sum_of_digits(int n){
    if(n>=0 && n<=9){
        return n;
    }
    else{
        return Sum_of_digits(n/10) + (n%10);
    }
}

int main(){
    int n;
    cout << "Enter the number : ";
    cin >> n;

    cout << "Sum of the digits is : " << Sum_of_digits(n);
}