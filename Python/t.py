a=int(input())
b=int(input())
x1=min(a,b)
l1=[]
for i  in range(x1+1):
    l1.append(i**2)
for i in range(a,b+1):
    print(i)
    if i in l1:
        break