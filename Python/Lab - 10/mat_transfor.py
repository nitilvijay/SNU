import numpy as np
import matplotlib.pyplot as plt
import math

file = open("text.txt", "r")

x = []
y = []

read = file.readlines()

for i in read:

    temp = i.split()
    x.append(int(temp[0]))
    y.append(int(temp[1]))

x = np.array(x)
y = np.array(y)
 
# a – slope of the line & b gives x intercept 
# Straight line approximation – Line of best fit 
a, b = np.polyfit(x, y, 1)
#add points to plot
plt.scatter(x, y)

#add line of best fit to plot: x is an array having independent variables 
plt.plot(x, a*x+b)  

ang = (math.atan(a))

r = [[(math.cos(ang)), (math.sin(ang))],[-((math.sin(ang))), (math.cos(ang))]]
r = np.array(r)

v = np.array((x,y))
print(v)

tran = np.dot(r,v)

for i in range(len(x)):

    tran[1][i] = 0

inv = np.transpose(r)

rev = np.dot(inv,tran)

print(rev)
# Finding error
err = 0

for l in range(2):

    for j in range(len(x)):

        err += ((v[l][j]-rev[l][j])**2)

print(err)
