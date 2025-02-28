#Convert two list to a dictionary
l1 = eval(input('Enter the list for keys'))
l2 = eval(input('Enter the list for values'))
d = {}

for i in range(len(l1)):

    d[l1[i]] = l2[i]

print(d)
