def is_palindrome(number):
    # Convert the number to string and check if it's equal to its reverse
    return str(number) == str(number)[::-1]
number=int(input("n: "))
if is_palindrome(number):
    print("The given number is a Palindrome number")
else:
    print("The given number is not a Palindrome number")