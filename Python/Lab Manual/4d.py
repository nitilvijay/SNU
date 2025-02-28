import math

a = int(input("Enter the number"))
b = int(input("Enter the number"))
theta = int(input('Enter the theta value'))

result = (a*math.cos(math.radians(theta))) - (b*math.cos(math.radians(theta)))

print(f"A cosθ − B sin(θ) = {result:.2}")

result =  a*(math.cos(math.radians(2*math.pi*theta)))

print(f"A cos(2πn) = {result:.2}")

result = math.exp(a*theta)

print(f"e^an = {result:.2}")

x1 = int(input("Enter x1"))
x2 = int(input("Enter x2"))
y1 = int(input("Enter y1"))
y2 = int(input("Enter y2"))

#Distance

result = math.sqrt(math.pow((x1-x2),2) + math.pow((y1-y2),2))

rad = int(input('Enter the radian value:'))

print("The angle value is: ",(math.degrees(rad)))

num = int(input("Enter a number: "))

print("log base2",math.log2(num),"log base 10:",math.log10(num))