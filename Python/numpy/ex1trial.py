import numpy as np

#1D Array
arr = np.array((1,2,3,4))
print(arr)

#2D Array
arr = np.array([[1,2],[3,4,]])
print("Dim of array:",arr.ndim)
print(arr)

#Defining Dim
arr = np.array([1,2,3,4], ndmin = 4)
print(f"Dim of arr: {arr.ndim}")
print(arr)