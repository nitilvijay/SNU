#linear search

lst = [1,4,3,2,22,24,646,68,563,68]

n = int(input("Enter the number to be serched for: "))

for i in range(len(lst)):
    if lst[i]==n:
        print(f"This is the index position: {i}")