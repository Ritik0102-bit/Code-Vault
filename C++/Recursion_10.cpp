// In this code we are going to make a function for calculating GCD (Greatest Comman Divisor) of two numbers using recursion
// According to Euclid algorithm GCD of x & y is equal to GCD of y & x % y 
// let x = 72  & y = 54
// so gcd(72,54) = gcd(54,18)  => so gcd is 18

#include<iostream>

using namespace std;

int GCD(int x,int y){
    if(y>x){
        return GCD(y,x); //if x is less than y
    }
    if(y==0){   // Base Case
        return x; 
    }
    else{
        return GCD(y,x % y);
    }
}

int main(){
    int x,y;
    cout << "Enter the value of x & y : ";
    cin >> x >> y;
    cout << "GCD of x & y is : ";
    cout << GCD(x,y);

    return 0;
}