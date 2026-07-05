# You are required to print a Zigzag pattern using stars (*). The Zigzag pattern alternates between printing stars in a left-aligned and right-aligned pattern on each line. The pattern repeats for n rows. No need to Get Confused its just spaces.

# Hint: Do you see difference in odd and even lines.

# Input Format

# An integer n (1 ≤ n ≤ 50) representing the number of rows for the Zigzag pattern.

# Constraints

# 1≤n≤50

# n is an integer, and the input will always be a valid integer. You are to print the pattern as specified, without any additional spaces or newlines.

# Output Format

# Print the Zigzag pattern where the stars (*) are arranged in alternating left and right aligned rows.

# Sample Input 0

# 3
# Sample Output 0

# *   *   *
#   *   *   *
# *   *   *
# Sample Input 1

# 4
# Sample Output 1

# *   *   *   *   
#   *   *   *   * 
# *   *   *   *   
#   *   *   *   * 


def print_zigzag(n: int):
    # Loop through each row
    for i in range(n):
        # Determine if the current row is odd or even
        if i % 2 == 0:
            # Odd row (0-based index: 0, 2, 4, ...) - left-aligned stars
            print("*   " * n)
        else:
            # Even row (0-based index: 1, 3, 5, ...) - right-aligned stars
            print("  " * (n - 1) + "*   " * n)

# Input reading
n = int(input())  # The number of rows

# Call the function to print the pattern
print_zigzag(n)
