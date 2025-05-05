A = []

file = open("text.txt","r")

# while True:

for i in range(4):

    read = file.readline()
    split = read.split()
    temp = []

    for a in range(len(split)):

        if split[a][0] == "-":
                temp.append((-1)*(float(split[a][1])))

        elif split[a].isalnum():
            i = 0
            num = ''
            
            while(i<len(split[a])):
                if split[a][i].isdigit():
                    num+= split[a][i]
                i+=1
            temp.append(float(num))

    
    A.append(temp)
print(A)
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

if (row == 4):
    w = A[3][-1]
    print("w = ", w)


