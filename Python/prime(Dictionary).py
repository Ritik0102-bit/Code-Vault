def prime(n):
    if n<2:
        return False
    for i in range(2,n):
        if n%i==0:
            return False
    
    return True
a=input("Enter numbers:")
li=list(map(int,a.split(",")))
d={}
for i in li:
    if prime(i):
        d[i]="prime"
    else:
        d[i]="not prime"
print(d)