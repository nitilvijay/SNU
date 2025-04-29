lst = eval(input("Enter the list"))

n_lst = []

for i in lst:
    for a in i:
        n_lst.append(a)

print(n_lst)


squared_list = [x**2 for x in flat_list]
print(squared_list)  


filtered_list = [x for x in flat_list if x % 2 == 0]
print(filtered_list)  
