d1 = {"a":100,"b":200,"c":300}
d2 = {"a":300,"b":200,"c":400}
d = {}

l1 = list(d1)
l1.extend(list(d2))
l1 = list(set(l1))

for i in l1:
    if (i in d1) and (i in d2):
        d[i] = d1[i]+d2[i]
    elif i in d1:
        d[i] = d1[i]
    else:
        d[i] = d2[i]
print(d)