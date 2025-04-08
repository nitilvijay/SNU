A = []

file = open("text.txt","r")

# while True:

for i in range(3):

    read = file.readline()
    split = read.split()
    temp = []

    for a in range(len(split)):

        if split[a][0] == "-":
                temp.append((-1)*(float(split[a][1])))

        elif split[a].isalnum():
            
            temp.append(float(split[a][0]))

    
    A.append(temp)

#making the first element as 1
row = len(A)
j = 0
while j<row:

    if A[j][j] != 1:

        val1 = A[j][j]
        for h in range(len(A[j])):

            A[j][h] = A[j][h]/val1


    
    for i in range(row):

        if A[i][j]!=0 and i!=j:
            
            num = 0
            
            val = A[i][j]
            for a in range(len(A[i])):
                
                A[i][a] = A[i][a]-(val*(A[j][num]))
                
                num+=1
        
    j+=1

x = A[0][-1]
y = A[1][-1]
z = A[2][-1]

print(f"x = {x}\ny = {y}\nz = {z}")


