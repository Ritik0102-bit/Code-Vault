// Compile Time --> Polymorphism

// 2. Operator Overloading

#include<iostream>

using namespace std;

class Complex {
public:
    int real; // Stores the real part 'a'
    int img;  // Stores the imaginary part 'b'

    // Constructor: Initializes the object
    Complex(int x, int y) {
        real = x;
        img = y;
    }

    // This is the overloaded '+' operator function ✨
    Complex operator+(Complex &c) {
        // Complex ans(0,0) since there's no default constructor.
        Complex ans(0, 0); 
        
        // Add the real part of the current object (this->real)
        // with the real part of the other object (c.real)
        ans.real = real + c.real;

        // Add the imaginary parts similarly
        ans.img = img + c.img;

        // Return the new Complex object which is the sum
        return ans;
    }
};


int main() {
    // Create two Complex objects using the constructor
    // c1 represents (1 + 2i)
    Complex c1(1, 2); 
    // c2 represents (1 + 3i)
    Complex c2(1, 3);

    // This is where the magic happens! 🚀
    // The compiler translates `c1 + c2` into `c1.operator+(c2)`
    Complex c3 = c1 + c2;

    // The result in c3 will be:
    // real = c1.real + c2.real -> 1 + 1 = 2
    // img  = c1.img + c2.img  -> 2 + 3 = 5
    // So, c3 represents (2 + 5i)

    // Print the result
    cout << c3.real << " i" << c3.img << endl;
}