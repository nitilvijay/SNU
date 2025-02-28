suml=0
sumr=0
li = eval(input("Enter the list of number"))

for i in range (len(li)):

    suml = sum(li[:i])
    sumr = sum(li[i+1:])

    if suml == sumr:
        print("The index is: ", i,"The value is: ",li[i])
          