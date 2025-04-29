string = "Underneath a huge oak tree there was of swine a huge company"
lst = []
i = 0

while i<len(string):
    temp =string[i:i+7]

    while len(temp)<7:
        temp+="X"
    
    lst.append(temp)
    i+=7

for a in range(7):
    for j in range(len(lst)):

        print(lst[j][a],end = "")
print()