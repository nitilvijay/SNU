string = "H cb  irhdeuousBdi   prrtyevdgp nir  eerit eatoreechadihf paken ge b te dih aoa.da tts tn "
print(len(string))
key = 9
num = int(len(string)/key)
print(num)

print(len(string))
lst = []
for i in range(num):
    lst.append([])

i = 0
while i<len(string):
    index = i%num
    lst[index].append(string[i])
    i+=1
print(lst)
for i in (lst):
    for a in i:
        print(a, end = '')
print() 
