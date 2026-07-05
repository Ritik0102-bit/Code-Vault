input_string = input()  # Accept the entire string input at once

words = input_string.split()  # Split the input into words

for word in words:
    if word == "STOP":
        break
    print(word,end=" ")
