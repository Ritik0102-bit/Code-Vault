# Find a string

# In this challenge, the user enters a string and a substring. You have to print the number of times that the substring occurs in the given string. String traversal will take place from left to right, not from right to left.

# Sample Input :-
# ABCDCDC
# CDC

# Sample Output :-
# 2

def count_substring(string, sub_string):
    count = 0
    sub_len = len(sub_string)
    
    # Loop through the string, stopping when there aren't enough characters left
    for i in range(len(string) - sub_len + 1):
        # Slice the string from current index 'i' to 'i + sub_len'
        if string[i:i+sub_len] == sub_string:
            count += 1
            
    return count

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)