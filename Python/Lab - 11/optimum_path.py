import numpy as np
file_pointer = open('text.txt')
array = [[x for x in line.split()] for line in file_pointer]

arr=list(array)
lst = [] #keeping track of the visited zeros
sum = 0
temp = []

for i in range(len(arr)):
    for j in range(len(arr)):
        arr[i][j]=int(arr[i][j])

#finding the min of row and subtracting
def sub_row(arr, index = -1):
    if index == -1:
        for i in range(len(arr)):
            mini=min(arr[i])
            for k in range(len(arr)):
                arr[i][k]-=mini
    else:
        temp = sorted(arr[index])
        mini = temp[1]
        for k in range(len(arr)):
            for i in range(len(arr)):
                arr[i][k]-=mini

print()

#finding min of columns and subtracting
def sub_col(arr, index = -1):
    if index == -1:
        print("here")
        for i in range(len(arr)):
            mini = 9999
            for k in range(len(arr)):
                if arr[k][i]<mini:
                    mini = arr[k][i]
            for k in range(len(arr)):
                arr[k][i]-=mini
    else:
        temp = []
        for i in range(len(arr)):
            temp.append(arr[i][index])
        print(temp)
        temp=sorted(temp)
        
        mini = temp[1]
        print(mini)
        for k in range(len(arr)):
            arr[k][index]-=mini
sub_row(arr)
print(arr)
sub_col(arr,1)

# taking only the unique zeros
for i in range(len(arr)):
    
    count = arr[i].count(0)
    if count==1:
        for j in range(len(arr[0])):
            if arr[i][j] == 0:
                sum+=array[i][j]
                lst.append(j)
print(array)