# def count_substring(string, sub_string):
#     li=[]
#     c=0
#     l1=len(string)
#     for i in range(l1-2):
#         li.append(string[i]+string[i+1]+string[i+2])
#     for i in li:
#         if sub_string==i:
#             c+=1
#     print(li)
#     return c

def count_substring(string, sub_string):
    count = 0
    for i in range(0, len(string)-1):
        if string.startswith(sub_string, i):
            count += 1

    return count

string = input().strip()
sub_string = input().strip()
count = count_substring(string, sub_string)
print(count)

# testcase 1
# string=ABCDCDC
# sub_string=CDC
# count=2