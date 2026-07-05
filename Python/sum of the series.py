# Write a program to input the value of x and n and print the sum of the following series:
# S=1-x+x^2-x^3+x^4-x^5+…….x^n
x=int(input("x:"))
n=int(input("n:"))
sum=1
for i in range(1,n+1):
    sum=sum+((-1)**i)*(x**i)
print(sum)