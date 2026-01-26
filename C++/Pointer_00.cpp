#include<iostream>

using namespace std;

int main(){
    int n=10;
    int *ptr=&n;  // it will store address of integer variable
    cout << "Address of variable : " << ptr << "\n";
    // we can print the value of integer variable with the derefecrence operator
    cout << "Value stored in the variable: " << *ptr << "\n";

    float x=3.3;
    float *fptr = &x;  // it will store address of float variable
    cout << "Address of variable : " << fptr << "\n";
    cout << "Value stored in the variable: " << *fptr << "\n"; 
    

    return 0;
}