from num2words import num2words

number_string = "123"
# Convert the string to an integer first
number = int(number_string)

# Convert to words
words = num2words(number)
print(words) 
# Output: one hundred and twenty-three