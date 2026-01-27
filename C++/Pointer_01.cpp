// we are going to update value of x with the help of pointers

#include<iostream>

using namespace std;

int main(){
    int x=0;

    int *ptr=&x;

    // we are changing value of x to 30
    *ptr=30;

    cout << x;
}