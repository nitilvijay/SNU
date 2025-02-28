#max of three numbers

num1 = int(input("Enter the number: "))
num2 = int(input("Enter the number: "))
num3 = int(input("Enter the number: "))

max = 0;

if num1>max:
    max = num1
if num2>max:
    max=num2
if num3>max:
    max = num3

print(f"This is the greatest: {max}")