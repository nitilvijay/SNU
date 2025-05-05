import numpy as np

# Function to calculate determinant of a 3x3 matrix
def det3(a):
    det = (a[0][0] * ((a[1][1] * a[2][2]) - (a[1][2] * a[2][1]))) - \
          (a[0][1] * ((a[1][0] * a[2][2]) - (a[1][2] * a[2][0]))) + \
          (a[0][2] * ((a[1][0] * a[2][1]) - (a[1][1] * a[2][0])))
    return det

# Read the coefficient matrix and augmented matrix from the file
A = []
B = []
aug = []

file = open("text.txt", "r")

for i in range(3):  # Assuming a 3x3 system
    read = file.readline()
    split = read.split()
    temp = []

    for a in range(len(split)):
        if split[a].isalnum():
            temp.append(int(split[a][0]))
        elif split[a] == '=':
            B.append(int(split[a + 1]))
            aug.append(temp + [int(split[a + 1])])
            break

    A.append(temp)

file.close()

# Convert to numpy arrays
A = np.array(A)
B = np.array(B)
aug = np.array(aug)

# Calculate the determinant of the coefficient matrix
det_A = det3(A)

# Calculate the rank of the coefficient matrix and augmented matrix
rank_A = np.linalg.matrix_rank(A)
rank_aug = np.linalg.matrix_rank(aug)

# Determine the solution type based on the rank
if rank_A == rank_aug:
    if rank_A == A.shape[1]:  # Number of variables
        print("The system has a unique solution.")
    else:
        print("The system has infinitely many solutions.")
else:
    print("The system has no solution (inconsistent system).")