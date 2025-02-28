[1,2,3,4,5,6,7,8,9]

lst = eval(input("Enter the lsit of numbers"))

for i in range(len(lst)-1):
    
    num1 = lst[i]
    num2 = lst[i+1]

    for a in range(len(lst)-1):

        if i!=lst[a]:
            
            if (i*lst[a] == i*lst[a+1]):

                tple
