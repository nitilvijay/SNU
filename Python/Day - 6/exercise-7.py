d = {"Name": "Zara", "Age": 7, "Class": "First"}

min = d["Name"]

for i in d:
    if type(d[i]) == int:
        print(type(d[i]))
        if int(d[i]) < min:
            min = d[i]
            key = i
print(key)