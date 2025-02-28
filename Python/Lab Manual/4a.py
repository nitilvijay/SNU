# Triangle
print('AREA OF A TRIANGLE')
base = float(input('Enter the base value: '))
height = float(input('Enter the height value: '))

area = 0.5 * base * height
print(f"The area of the triangle is: {area:.2f}")

# Parallelogram
print("\nPARALLELOGRAM")
base = float(input('Enter the base value: '))
height = float(input('Enter the height value: '))

area = base * height
print(f"The area of the parallelogram is: {area:.2f}")

# Cylinder
print("\nAREA OF CYLINDER")
height = float(input('Enter the height value: '))
radius = float(input("Enter the radius: "))

area = (2 * 3.14 * radius * height) + (2 * 3.14 * (radius ** 2))
print(f"The area of the cylinder is: {area:.2f}")

# Cone
print("\nAREA OF CONE")
radius = float(input("Enter the radius of the cone: "))
slant_height = float(input("Enter the slant height of the cone: "))

area = 3.14 * radius * (radius + slant_height)
print(f"The area of the cone is: {area:.2f}")

# Sphere
print("\nAREA OF SPHERE")
radius = float(input("Enter the radius of the sphere: "))

area = 4 * 3.14 * (radius ** 2)
print(f"The area of the sphere is: {area:.2f}")

# Rectangular Prism
print("\nAREA OF RECTANGULAR PRISM")
length = float(input("Enter the length of the rectangular prism: "))
width = float(input("Enter the width of the rectangular prism: "))
height = float(input("Enter the height of the rectangular prism: "))

area = 2 * (length * width + width * height + height * length)
print(f"The surface area of the rectangular prism is: {area:.2f}")
    