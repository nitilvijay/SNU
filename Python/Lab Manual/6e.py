prev = 0
next = 1

n = int(input("Enter the number"))

print(1, end = " ")

for i in range(2,n+1):

    if i%2==0:
        print(-1*((prev+next)**i), end=" ")
    else:
        print((prev+next)**i, end=" ")
    
    prev = next
    next = prev+next
