lst = []
max = 0
count = 0
while True:
    tple = eval(input("Enter the tuple containing the percentage and the name"))
    if type(tple)!=tuple:
        break
    else:
        if tple[0]>max:
            max = tple[0]
            max_count = count

        lst.append(tple)
    count+=1

print(f"This is the student with the highest mark: {lst[max_count]}")