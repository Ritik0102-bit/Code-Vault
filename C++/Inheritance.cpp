// Inheritance is a core pillar of Object-Oriented Programming (OOP) in C++. It allows you to create a new class (the derived or child class) that inherits attributes and methods from an existing class (the base or parent class). It’s perfect for code reuse and establishing an "is-a" relationship (e.g., a Car is a Vehicle).

// Here is a breakdown of the most common inheritance scenarios, specifically focusing on how to pass parameters from a derived class to a base class.

// The Golden Rule of Constructors in Inheritance
// Before jumping into the code, you need to know one strict rule: Base class constructors are always executed before derived class constructors. Because the base class gets built first, you cannot pass parameters to the base class from inside the body { ... } of the derived class's constructor. Instead, you must use a member initializer list.

// Scenario 1: Single Inheritance (Passing parameters to one Base Class)
// This is the most common scenario. We have one base class that requires a parameter, and a derived class that provides it.


#include <iostream>
#include <string>
using namespace std;

// Base Class
class Vehicle {
protected:
    int wheels;
public:
    // Parameterized constructor for Base
    Vehicle(int w) {
        wheels = w;
        cout << "Vehicle constructor called. Wheels: " << wheels << endl;
    }
};

// Derived Class
class Car : public Vehicle {
private:
    string brand;
public:
    // Derived constructor passing parameter 'w' to Base constructor using an initializer list ( : )
    Car(string b, int w) : Vehicle(w) {
        brand = b;
        cout << "Car constructor called. Brand: " << brand << endl;
    }
};

int main() {
    Car myCar("Toyota", 4);
    return 0;
}
/* OUTPUT:
Vehicle constructor called. Wheels: 4
Car constructor called. Brand: Toyota
*/


// Scenario 2: Multilevel Inheritance (Passing parameters up a chain)
// Here, a class inherits from a derived class (A -> B -> C). Parameters must be passed up the chain, one level at a time. The child passes to the parent, and the parent passes to the grandparent.


#include <iostream>
#include <string>
using namespace std;

// Grandparent Class
class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {
        cout << "Person built: " << name << endl;
    }
};

// Parent Class
class Employee : public Person {
protected:
    int empId;
public:
    // Passes 'n' up to Person
    Employee(string n, int id) : Person(n), empId(id) {
        cout << "Employee built with ID: " << empId << endl;
    }
};

// Child Class
class Manager : public Employee {
private:
    string department;
public:
    // Passes 'n' and 'id' up to Employee
    Manager(string n, int id, string dept) : Employee(n, id), department(dept) {
        cout << "Manager built for dept: " << department << endl;
    }
};

int main() {
    Manager mgr("Alice", 101, "IT");
    return 0;
}
/* OUTPUT:
Person built: Alice
Employee built with ID: 101
Manager built for dept: IT
*/


// Scenario 3: Multiple Inheritance (Passing parameters to multiple Base Classes)
// C++ allows a derived class to inherit from more than one base class at the same time. You can pass parameters to all base classes by separating their constructor calls with a comma in the initializer list.


#include <iostream>
#include <string>
using namespace std;

// Base Class 1
class Engine {
protected:
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {
        cout << "Engine built (" << hp << " HP)" << endl;
    }
};

// Base Class 2
class Radio {
protected:
    string radioBrand;
public:
    Radio(string rBrand) : radioBrand(rBrand) {
        cout << "Radio built (" << radioBrand << ")" << endl;
    }
};

// Derived Class inheriting from BOTH Engine and Radio
class SportsCar : public Engine, public Radio {
private:
    string model;
public:
    // Passes parameters to both base classes simultaneously
    SportsCar(string m, int hp, string rBrand) : Engine(hp), Radio(rBrand) {
        model = m;
        cout << "SportsCar built: " << model << endl;
    }
};

int main() {
    SportsCar myFerrari("Ferrari 488", 661, "Bose");
    return 0;
}
/* OUTPUT:
Engine built (661 HP)
Radio built (Bose)
SportsCar built: Ferrari 488
*/


// Note on Multiple Inheritance: The base class constructors are called in the order they are declared in the class definition (class SportsCar : public Engine, public Radio), not the order they appear in the initializer list.


// Scenario 4: Mixing Default and Parameterized Constructors
// Sometimes, a base class might have both a default constructor (no parameters) and a parameterized constructor. If you don't explicitly call a base constructor in the derived class's initializer list, C++ will automatically call the base class's default constructor.


#include <iostream>
using namespace std;

class Animal {
public:
    Animal() { cout << "Default Animal constructor." << endl; }
    Animal(int age) { cout << "Parameterized Animal constructor. Age: " << age << endl; }
};

class Dog : public Animal {
public:
    // Calls default Animal() automatically
    Dog() { 
        cout << "Dog default constructor." << endl; 
    }
    
    // Explicitly calls Animal(int age)
    Dog(int age) : Animal(age) { 
        cout << "Dog parameterized constructor." << endl; 
    }
};

int main() {
    cout << "-- Creating pup1 --" << endl;
    Dog pup1; 
    
    cout << "\n-- Creating pup2 --" << endl;
    Dog pup2(5);
    
    return 0;
}
/* OUTPUT:
-- Creating pup1 --
Default Animal constructor.
Dog default constructor.

-- Creating pup2 --
Parameterized Animal constructor. Age: 5
Dog parameterized constructor.
*/