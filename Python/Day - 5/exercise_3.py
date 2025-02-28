string = input("Enter the string")
max = 0
tple = ()
for i in string:
    count = 0
    for a in range(len(string)):

        if i == string[a]:
            count+=1
    if count>max:
        max = count
        tple = (max, i)

print(f"This is the most occuring letter: {tple}")
