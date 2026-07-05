def unique_combinations(numbers):
    li= []
    n = len(numbers)
    for i in range(n):
        for j in range(n):
            for k in range(n):
                # Ensure indices are different
                if i != j and j != k and i != k:
                    li.append([numbers[i], numbers[j], numbers[k]])
    return li

numbers = [1,2,3]
print("Unique Combinations:",unique_combinations(numbers))