# # 1. Introduction to Python 🐍
# Python is a high-level, interpreted, general-purpose programming language. Its design philosophy emphasizes code readability with its notable use of significant indentation. It's dynamically-typed and garbage-collected.

# Interpreted: Code is executed line by line, which makes debugging easier.

# High-Level: Abstracts away complex details of the computer's hardware.

# Dynamically-Typed: You don't need to declare the type of a variable when you create it.

# General-Purpose: Can be used for web development, data science, automation, and more.

# ## 2. Basic Syntax and Variables
# Python syntax is clean and readable.

# Indentation: Python uses indentation (usually 4 spaces) to define blocks of code, instead of curly braces {}.

# Comments: Use the hash symbol # for single-line comments. For multi-line comments, you can use triple quotes ''' or """.

# Variables: Variables are containers for storing data values. You create a variable by assigning a value to it using the equals sign =.

# Python

# This is a comment
x = 10          # x is an integer
name = "Alice"  # name is a string
pi = 3.14       # pi is a float

# Python is case-sensitive
age = 25
Age = 30 # 'age' and 'Age' are different variables
## 3. Data Types
# Python has several built-in data types.

# Primitive Types
# Integers (int): Whole numbers, like 10, -5, 0.

# Floats (float): Numbers with a decimal point, like 3.14, -0.001.

# Strings (str): Sequences of characters, enclosed in single ' or double " quotes.

# Booleans (bool): Represent truth values, either True or False.

# Data Structures (Collections)
# Lists (list): Ordered, mutable (changeable) collections of items. Enclosed in square brackets [].

# Python

my_list = [1, "hello", 3.14, True]
my_list[1] = "world" # Lists are mutable
print(my_list) # Output: [1, 'world', 3.14, True]

# Tuples (tuple): Ordered, immutable (unchangeable) collections. Enclosed in parentheses ().

# Python

my_tuple = (1, "hello", 3.14)
# my_tuple[1] = "world" # This would cause an error

# Dictionaries (dict): Unordered collections of key-value pairs. Enclosed in curly braces {}. Keys must be unique and immutable.

# Python

my_dict = {"name": "Bob", "age": 30}
print(my_dict["name"]) # Output: Bob

# Sets (set): Unordered, unindexed collections of unique items. Enclosed in curly braces {}.

# Python

my_set = {1, 2, 3, 3, 4}
print(my_set) # Output: {1, 2, 3, 4}

#  4. Control Flow
# Control flow statements direct the order in which code is executed.

# Conditional Statements
# Used to perform different actions based on different conditions.

# Python

x = 10
if x > 5:
    print("x is greater than 5")
elif x == 5:
    print("x is 5")
else:
    print("x is less than 5")

# Loops
# Used to execute a block of code repeatedly.

# for loop: Iterates over a sequence (like a list, tuple, or string).

# Python

fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)

# while loop: Executes a block of code as long as a condition is true.

# Python

count = 0
while count < 5:
    print(count)
    count += 1 # Increment count

#  5. Functions
# A function is a block of code that only runs when it is called. You can pass data, known as parameters, into a function.

# Defining a function: Use the def keyword.

# Returning a value: Use the return keyword.

# Python

# A simple function
def greet(name):
  """This function greets the person passed in as a parameter."""
  print(f"Hello, {name}!")

# Function with a return value
def add_numbers(x, y):
  return x + y

# Calling functions
greet("Charlie")          # Output: Hello, Charlie!
result = add_numbers(5, 3)
print(result)             # Output: 8


## 6. Object-Oriented Programming (OOP)
# Python is an object-oriented programming language. Almost everything in Python is an object, with its properties and methods.

# Class: A blueprint for creating objects.

# Object: An instance of a class.

# Python

class Dog:
  # The __init__() function is a constructor, called when an object is created
  def __init__(self, name, age):
    self.name = name
    self.age = age

  def bark(self):
    return "Woof!"

# Creating an object (instance) of the Dog class
my_dog = Dog("Buddy", 4)

print(my_dog.name) # Accessing object properties
print(my_dog.bark()) # Calling object methods


## 7. Modules and Packages
# Module: A file containing Python code (functions, classes, etc.). You can import it into other files to reuse its code.

# Package: A collection of modules.

# You use the import statement to use code from a module.

# Python

# import the 'math' module
import math

print(math.sqrt(16)) # Output: 4.0

# You can also import specific functions
from datetime import datetime

print(datetime.now())


## 8. File Handling 📂
# Python has functions for creating, reading, updating, and deleting files.

# Use the open() function to open a file. It takes two parameters: the filename and the mode ('r' for read, 'w' for write, 'a' for append).

# It's good practice to use the with statement because it automatically closes the file for you.

# Python

# Writing to a file (will create the file if it doesn't exist)
with open("example.txt", "w") as file:
  file.write("Hello, file!")

# Reading from a file
with open("example.txt", "r") as file:
  content = file.read()
  print(content)


## 9. Exception Handling
# When an error occurs during execution, it's called an exception. You can use try...except blocks to handle these errors gracefully instead of letting your program crash.

# Python

try:
  result = 10 / 0
except ZeroDivisionError:
  print("Error: You cannot divide by zero!")
finally:
  # This block executes regardless of whether an error occurred or not
  print("Execution finished.")