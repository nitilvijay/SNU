#Binary search

t = list()
for i in range(1,1000):
    t.append(i)
t = tuple(t)
value = int(input("Enter the value to be found"))
start = 0
end = len(t)-1

while(start<=end):

    mid = start + (end-start)//2

    if t[mid] == value:
        print("value found")
        break

    elif value > t[mid]:
        start = mid+1

    else:

        end = mid-1
else:
    print("Not found")