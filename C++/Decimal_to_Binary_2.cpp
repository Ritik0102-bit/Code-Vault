#include<iostream>

using namespace std;

int Decimal_to_Binary(int DecNumber){
    int BinaryNum=0;
    int power=1; // 10^0 -> 10^1 -> 10^3 -> 10^4

    while(DecNumber>0){
        int rem=DecNumber % 2;
        BinaryNum += rem * power;
        power *= 10;
        DecNumber/=2;
    }
    return BinaryNum;
}

int main(){
    int decimal;
    cin >> decimal;
    int Binary = Decimal_to_Binary(decimal);
    cout << Binary << endl;
    return 0;
}