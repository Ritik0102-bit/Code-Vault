# Given a number 𝑁 N, determine if it is the factorial of some integer. A number 𝑁 N is a factorial if there exists an integer 𝑘 k such that 𝑘

# !
# 𝑁 k!=N.

# Write a function is_factorial(n: int) -> bool that returns True if the number is a factorial of some integer, otherwise returns False.

# Input Format

# A single integer 𝑁 N (1 ≤ N ≤ 10^9).

# Constraints

# 1 ≤ 𝑁 ≤ 1 0 9 1≤N≤10 9

# 𝑁 N is a positive integer, and its value can be as large as 1 0 9 10 9 . We are looking to check if 𝑁 N can be expressed as 𝑘 ! k! (where 𝑘 k is a positive integer). Additional Constraints: The input 𝑁 N is guaranteed to be a valid integer within the given range. You must check whether 𝑁 N is a factorial of any integer efficiently.

# Output Format

# Return True if 𝑁 N is a factorial, otherwise return False.

# Sample Input 0

# 6
# Sample Output 0

# True
# Sample Input 1

# 123456789
# Sample Output 1

# False

def is_factorial(n: int) -> bool:
    factorial = 1
    k = 1
    
    while factorial < n:
        k += 1
        factorial *= k
    
    return factorial == n

# Input reading
n = int(input())

# Function call and output
print(is_factorial(n))
