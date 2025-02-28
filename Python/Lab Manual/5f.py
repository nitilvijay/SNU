# Obtain the lengths of the 4 sides of a quadrilateral and the angles at each corner of
# the quadrilateral. Verify if the dimensions represent a valid quadrilateral and if so,
# check whether the dimensions represent a square, a rectangle, or neither.

import math

def is_valid_quad(sides, angles):
    return sum(angles) == 360 and all(side > 0 for side in sides)

def get_quad_type(sides, angles):
    if not is_valid_quad(sides, angles):
        return "Invalid quadrilateral"
    
    if len(set(sides)) == 1 and len(set(angles)) == 1 and angles[0] == 90:
        return "Square"
    elif len(set(sides)) == 2 and len(set(angles)) == 1 and angles[0] == 90:
        return "Rectangle"
    else:
        return "Neither square nor rectangle"

side_lengths = []
corner_angles = []

for i in range(4):
    side_length = float(input(f"Enter length of side {i+1}: "))
    side_lengths.append(side_length)

for i in range(4):
    corner_angle = float(input(f"Enter angle at corner {i+1}: "))
    corner_angles.append(corner_angle)

quad_type = get_quad_type(side_lengths, corner_angles)
print(f"The quadrilateral is: {quad_type}")

if __name__ == "__main__":
    main()



