// Prototypes in JS :-
// A javaScript object is an entity having state and behavior (properties and method).
// We can set prototype using __proto__ property.

// *If object & prototype have same method,
// object’s method will be used.


// Classes in JS :-

// Class is a program-code template for creating objects.
// Those objects will have some state (variables) & some behaviour (functions) inside it.

class Person {
    constructor(name, age, gender, address) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.address = address;
    }

    sayHello() {
        console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
    }
}

const person = new Person("Rahul", 25, "Male", {city: "Delhi", country: "India"});

person.sayHello(); // Output: Hello, my name is Rahul and I am 25 years old.


// Inheritance in JS :-

class Student extends Person {
    constructor(name, age, gender, address, school) {
        super(name, age, gender, address);
        this.school = school;
    }

    sayHello() {
        console.log(`Hello, my name is ${this.name} and I am ${this.age} years old.`);
        console.log(`I am a student of ${this.school}.`);
    }
}

let student = new Student("Ritik", 26, "Male", {city: "Mumbai", country: "India"}, "IIT Bombay");
student.sayHello(); // Output: Hello, my name is Ritik and I am 26 years old. I am a student of IIT Bombay. 