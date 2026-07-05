def print_formatted(number):
    width = len(bin(number)[2:])
    for i in range(1,number+1):
        decimal = i
        octal = oct(i)[2:]
        hexadecimal = hex(i)[2:].upper()
        binary = bin(i)[2:]
        print(f'{decimal:>{width}} {octal:>{width}} {hexadecimal:>{width}} {binary:>{width}}')      

n = int(input())
print_formatted(n)

# Given an integer,n, print the following values for each integer i from 1 to n:

# Decimal
# Octal
# Hexadecimal (capitalized)
# Binary
# Function Description

# Complete the print_formatted function in the editor below.

# print_formatted has the following parameters:

# int number: the maximum value to print
# Prints

# The four values must be printed on a single line in the order specified above for each i from  1 to number. Each value should be space-padded to match the width of the binary value of  number and the values should be separated by a single space.