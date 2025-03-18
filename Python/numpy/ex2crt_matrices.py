import numpy as np

# Define a permutation vector (custom order of rows)

a = np.array([1,2,3,4])
ind = [2,0,3,1]
print(a[ind])

print("Identity matrix")

i = np.identity(3)
print(i)