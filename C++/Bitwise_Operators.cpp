// And operator: &  -> it gives 1 only if both bits are 1
// Or operator: |   -> it gives 1 if either of the bits is 1
// Xor operator: ^  -> it gives 1 if the both bits are different  &  if both bits are same it gives 0
// Not operator: ~  -> it gives 1 if the bit is 0

// left shift:   <<  -> it shifts the bits to the left
// a << b: shifts a to the left by b bits
// answer = a * 2^b

// right shift:  >>  -> it shifts the bits to the right
// a >> b: shifts a to the right by b bits
// answer = a / 2^b

#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int b = 3;

    cout << a << " & " << b << " = " << (a & b) << endl;
    cout << a << " | " << b << " = " << (a | b) << endl;
    cout << a << " ^ " << b << " = " << (a ^ b) << endl;
    cout << ~a << " = " << ~a << endl;
    
}

