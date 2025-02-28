str = input("Enter the string")

char = {}

for i in str:
    if i in char:
        char[i]+=1
    else:
        char[i]=0
    
lst = char.values()
