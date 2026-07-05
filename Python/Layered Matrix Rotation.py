# You are given an NxN matrix, where N is an even integer. Your task is to perform a layered 90-degree clockwise rotation of each concentric "layer" of the matrix. Starting from the outermost layer, rotate each layer clockwise by 90 degrees, and repeat for each subsequent inner layer until the innermost layer is reached. The innermost elements of the matrix (if only one central element exists) should remain unchanged. You are required to perform this rotation in place without using additional memory for temporary storage.

# Input Format

# An integer N representing the dimensions of the matrix (2 ≤ N ≤ 1000; always even).

# A 2D array M of dimensions N x N, where each element is an integer (-10^5 ≤ M[i][j] ≤ 10^5).

# Constraints

# 2≤N≤1000, where

# N is always an even integer. Matrix M is an N x N matrix. Each element in M is an integer: − 1 0 5 ≤ 𝑀 [ 𝑖 ] [ 𝑗 ] ≤ 1 0 5 −10 5 ≤M[i][j]≤10 5 . Rotation should be performed in place, without additional memory for storage.

# Output Format

# The matrix after performing the layered 90-degree clockwise rotation on each concentric layer.

# Sample Input 0

# 2
# 42 17
# 99 23
# Sample Output 0

# 99 42
# 23 17
# Sample Input 1

# 3
# 1 2 3
# 4 5 6
# 7 8 9
# Sample Output 1

# 7 4 1
# 8 5 2
# 9 6 3

def rotate_matrix(M, N):
    # Loop over each layer
    for layer in range(N // 2):
        first = layer
        last = N - layer - 1
        
        # Rotate the current layer
        for i in range(first, last):
            # Offset for the inner loop
            offset = i - first
            
            # Save the top element
            top = M[first][i]
            
            # Move elements from left to top
            M[first][i] = M[last - offset][first]
            
            # Move elements from bottom to left
            M[last - offset][first] = M[last][last - offset]
            
            # Move elements from right to bottom
            M[last][last - offset] = M[i][last]
            
            # Move elements from top to right
            M[i][last] = top
    
    return M

# Input
N = int(input())  # Size of the matrix
M = [list(map(int, input().split())) for _ in range(N)]  # The NxN matrix

# Rotate the matrix in place
rotate_matrix(M, N)

# Output the rotated matrix
for row in M:
    print(" ".join(map(str, row)))
