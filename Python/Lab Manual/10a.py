#Bubble sort

lst = eval(input("Enter the numbers"))
k = int(input("Enter the value of 'k' to find the kth lrgest nmber: "))

for i in range(1,len(lst)):
    swapped = False
    for a in range(len(lst)-i):

        if lst[a]>lst[a+1]:

            lst[a], lst[a+1] = lst[a+1], lst[a]
            swapped = True
    if swapped == False:
        break 

print("This is the kth largest number: ",lst[(-1)*k])
