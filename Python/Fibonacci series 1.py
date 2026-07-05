def fibonacci(n):
    # Initialize the first two terms
    fib = [0, 1]
    
    # Compute the next terms until we reach the nth term
    for i in range(2, n):
        next_term = fib[i-1] + fib[i-2]
        fib.append(next_term)
    
    # Print the first n fibonacci numbers
    print(" ".join(map(str, fib[:n])))

n = int(input())
fibonacci(n)