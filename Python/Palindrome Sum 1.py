# You are given a list of integers. Your task is to check if the sum of all the integers in the list is a palindrome or not.

# A number is said to be a palindrome if it reads the same forward and backward. For example, 121, 343, and 12321 are palindromes, while 123 and 5678 are not.

# Input Format

# The first line of input contains an integer 𝑛 n, the number of elements in the list. 1 ≤ 𝑛 ≤ 1 0 4 1≤n≤10 4 . The second line contains 𝑛 n space-separated integers, the elements of the list. Each integer nums [ 𝑖 ] nums[i] is in the range − 1 0 6 ≤ nums [ 𝑖 ] ≤ 1 0 6 −10 6 ≤nums[i]≤10 6 .

# Constraints

# 1 ≤ len(nums) ≤ 1 0 4 1≤len(nums)≤10 4

# − 1 0 6 ≤ nums [ 𝑖 ] ≤ 1 0 6 −10 6 ≤nums[i]≤10 6

# Output Format

# Return True if the sum of the integers is a palindrome, otherwise return False.

# Sample Input 0

# 2
# 121 121
# Sample Output 0

# True
# Sample Input 1

# 4
# 1 2 3 4
# Sample Output 1

# False

def is_palindrome(number: int) -> bool:
    # Convert the number to string and check if it's equal to its reverse
    return str(number) == str(number)[::-1]

def check_sum_palindrome(n: int, nums: list) -> bool:
    # Calculate the sum of the list
    total_sum = sum(nums)
    
    # Check if the sum is a palindrome
    return is_palindrome(total_sum)

# Input reading
n = int(input())  # Number of integers in the list
nums = list(map(int, input().split()))  # The list of integers

# Output the result
print(check_sum_palindrome(n, nums))
