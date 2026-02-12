// Decimal to Binary Conversion Using Stack

#include <iostream>
#include <stack>

using namespace std;

void decimalToBinaryStack(int n) {
    // 1. Handle edge case for 0
    if (n == 0) {
        cout << "0" << endl;
        return;
    }

    stack<int> s;

    // 2. Push remainders onto the stack
    while (n > 0) {
        int remainder = n % 2;
        s.push(remainder);
        n = n / 2;
    }

    // 3. Pop from stack to print in correct order (LIFO)
    cout << "Binary: ";
    while (!s.empty()) {
        cout << s.top(); // Look at the top element
        s.pop();         // Remove it
    }
    cout << endl;
}

int main() {
    int number = 13;
    decimalToBinaryStack(number);
    return 0;
}