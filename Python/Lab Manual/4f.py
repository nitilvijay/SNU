import math

a = float(input("Enter coefficient a: "))

b = float(input("Enter coefficient b: "))

c = float(input("Enter coefficient c: "))


root1 = (-b + math.sqrt(b**2 - 4*a*c)) / (2 * a)

root2 = (-b - math.sqrt(b**2 - 4*a*c)) / (2 * a)


print(f"Roots of the equation: {root1:.2f} and {root2:.2f}")
