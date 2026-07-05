# The Tribonacci sequence is a variant of the Fibonacci sequence, where each term is the sum of the previous three terms. The sequence starts with three predefined values.
# Given the first three terms of the sequence, calculate the n-th term.

# a(n) = a(n-1) + a(n-2) + a(n-3)
# with a(0) = a(1) = 0, a(2) = 1

# Given an integer n, print the entire Tribonacci sequence up to the n-th term First few numbers in the Tribonacci Sequence are 0, 0,1, 1, 2, 4, 7, 13, 24, 44, 81

# Input Format
# Take a value n as input(integer)
# Constraints
# 1≤n≤100

# Output Format
# task is to print first n Tribonacci Numbers

# Sample Input 0
# 1
# Sample Output 0
# 0

# Sample Input 1
# 5
# Sample Output 1
# 0 0 1 1 2



def tribonacci(n):
    # Initialize the first three terms
    trib = [0, 0, 1]
    
    # Compute the next terms until we reach the nth term
    for i in range(3, n):
        next_term = trib[i-1] + trib[i-2] + trib[i-3]
        trib.append(next_term)
    
    # Print the first n Tribonacci numbers
    print(" ".join(map(str, trib[:n])))

# Input reading
n = int(input())

# Function call to print the result
tribonacci(n)