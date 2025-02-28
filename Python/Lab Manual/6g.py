N = int(input("Enter the number (N): "))
L = int(input("Enter the number of iterations (L): "))

x = N / 2  


for _ in range(L):
    x = (x + N / x) / 2  
    print(x)

print(f"Approximated square root of {N} after {L} iterations: {x}")
