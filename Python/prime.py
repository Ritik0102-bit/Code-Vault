def prime(n):
    if n<2:
        return False
    for i in range(2,n):
        if n%i==0:
            return False
    return True
n=int(input("Enter number:"))
if(prime(n)):
    print("It is a Prime Number")
else:
    print("It is not a Prime Number")
