# file=open('text.txt','r+')
# a=file.read()
# for i in a:
#     if i==' ':
#         i='#'
# b=file.read()
# for i in b:
#     print(i)


# Open file in read and write mode
with open('text.txt', 'r+') as file:
    content = file.read()

    # Manually replace spaces with '#'
    modified = ''
    for char in content:
        if char == ' ':
            modified += '#'
        else:
            modified += char


    # Move cursor to start of file
    file.seek(0)
    file.write(modified)
    

file=open('text.txt','r+')
a=file.read()
for i in a:
    print(i)