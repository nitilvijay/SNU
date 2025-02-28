# dentify if a point (x,y) lies inside, outside, or on the circumference of a circle of
# radius "r", centered at the origin. Obtain the values of x, y, and r from the user.

import math

x = float(input("Enter the x-coordinate of the point: "))

y = float(input("Enter the y-coordinate of the point: "))  

r = float(input("Enter the radius of the circle: "))
distance = math.sqrt(x**2 + y**2)

if distance < r:
    print("The point lies inside the circle.")
elif distance == r:
    print("The point lies on the circumference of the circle.")
else:
    print("The point lies outside the circle.")

    