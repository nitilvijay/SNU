#Program to check perfect number or happy number

def perfect(num):

    sum=0

    for i in range(1,num):

        if num%i==0:
            sum+=i
    
    if sum == num:
        print(num, "Is a perfect number")
    else:
        print("Not a perfect number")

def happy(num):
    sum = num
    while sum>9:
        numstr=str(sum)
        sum = 0
        for i in numstr:
            sum += (int(i))**2


    if sum==1:
        print("It is a happy number")
    else:
        print("Not a happy number")

while True:
    number = int(input("Enter the number"))
    choice = int(input("1. Perfect\n2. Happy\n3. Exit\n"))

    if choice == 1:
        perfect(number)
    elif choice == 2:
        happy(number)
    else:
        break

