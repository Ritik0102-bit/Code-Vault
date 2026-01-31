// In this code we are going to make a function for printing sequence from 1 to n using recursion

#include<iostream>

using namespace std;

void print_sequence(int n){
    if(n<1){    // Base Case
        return;
    }
    print_sequence(n-1);  // This is the assumption
    cout << n << " " ;    // This is the self work
}

int main(){
    int n;

    cout << "Enter the no. : ";
    cin >> n;

    print_sequence(n);

    return 0;

}