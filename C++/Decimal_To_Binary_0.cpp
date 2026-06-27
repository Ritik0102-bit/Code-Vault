// It is the best approach Using BITWISE Operators

// Time complexity:- O(1)
//  It runs in O(1) time (technically O(32) or O(64) which is constant) and uses bit-level logic, which is faster than division.

#include <iostream>
using namespace std;

void Decimal_To_Binary_Bitwise(int n) {
    // 31 is the standard for signed 32-bit integers
    // We iterate from the Most Significant Bit (MSB) down to 0
    for (int i = 31; i >= 0; i--) {
        // Shift 'n' to the right by 'i' positions
        int k = n >> i;
        
        // Check if the 0th bit is 1 or 0
        if (k & 1) 
            cout << "1";
        else 
            cout << "0";
    }
    cout << endl;
}

int main(){
    int n;
    cin>>n;

    Decimal_To_Binary_Bitwise(n);

    return 0;
}