n=4
i=1
for i in range(1,n+1):
    if(n%i==0 and i%2==0):
        print(i,end=" ")
else:
    print(-1)