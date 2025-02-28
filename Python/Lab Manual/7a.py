string = input("Enter the string")

for i in range(len(string)):
    for a in range(len(string),i,-1):
        temp = ""
        for g in range(i,a):
            temp+=string[g]
        
        if temp == temp[::-1]:
            print(temp)