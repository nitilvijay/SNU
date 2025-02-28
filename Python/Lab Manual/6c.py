#Print the following pattern for 2N-1 rows.

n = int(input("Enter the number of rows: "))

row = n

for i in range(row):
    #print(" "*i, end = "")
    print(row-i)
    #print((" "+(str(row-i)))*(row-i))

for a in range(row-2,0,-1):
    print(" "*a, end = "")
    print((" "+(str(a)))*(a))