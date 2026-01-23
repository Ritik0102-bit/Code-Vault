// Run Time --> Polymorphism

#include <iostream>
using namespace std;

class Parent {
public:
    virtual void print() {
        cout << "parent class" << endl;
    }

    void show() {
        cout << "parent class" << endl;
    }
};

class Child : public Parent {
public:
    void print() {
        cout << "child class" << endl;
    }

    void show() {
        cout << "child class" << endl;
    }
};

int main() {
    Parent *p; // A pointer to a Parent object
    Child c;   // A Child object

    p = &c;    // Make the Parent pointer point to the Child object

    // Calling virtual function 'print()'
    p->print(); // Output: "child class"
                // Explanation: Because 'print' is virtual, C++ looks at the
                // actual object 'c' (which is a Child) and calls Child's print().

    // Calling non-virtual function 'show()'
    p->show();  // Output: "parent class"
                // Explanation: 'show' is not virtual, so C++ only considers the
                // pointer type 'Parent*' and calls Parent's show().

    // Direct calls via Child object
    c.print(); // Output: "child class"
    c.show();  // Output: "child class"

    return 0;
}