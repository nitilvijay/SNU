import numpy as np
file_pointer = open('text.txt')
array = [[x for x in line.split()] for line in file_pointer]

arr=list(array)
lst = [] #keeping track of the visited zeros
sum = 0

for i in range(len(arr)):
    for j in range(len(arr)):
        arr[i][j]=int(arr[i][j])

#finding the min of row and subtracting
for i in arr:
    min=(i[0])
    for j in range(1,len(i)):
        if ((i[j])<min):
            min=(i[j])
    for k in range(len(i)):
        i[k]-=min

print()

#finding min of columns and subtracting
for i in range(len(arr)):
    min=arr[0][i]
    for j in range(1,len(arr)):
        if arr[j][i]<min:
            min=arr[j][i]
    for k in range(len(arr)):
        arr[k][i]-=min

# taking only the unique zeros
for i in range(len(arr)):
    
    count = arr[i].count(0)
    if count==1:
        for j in range(len(arr[0])):
            if arr[i][j] == 0:
                sum+=array[i][j]
                lst.append(j)
print(lst)