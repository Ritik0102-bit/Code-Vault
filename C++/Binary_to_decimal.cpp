#include<iostream>

using namespace std;

int Binary_to_Decimal(int BinaryNum){
    int decimal=0;
    int power=1;
    while(BinaryNum>0){
        int rem = BinaryNum % 10;
        decimal += rem * power;
        BinaryNum /= 10;
        power *= 2;
    }
    return decimal;
}

int main(){
    int n;
    cin >> n;
    int decimal = Binary_to_Decimal(n);
    cout << decimal;
}