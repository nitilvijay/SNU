import numpy as np
import matplotlib.pyplot as plt
import math

file_pointer = open('text.txt')
array = [[x for x in line.split()] for line in file_pointer]
array=array[1:len(array)]
x=[]
y=[]
for i in array:
    x.append(int(i[0]))
    y.append(int(i[1]))
v=[[i for i in x],[j for j in y]]
x=np.array(x)
y=np.array(y)
v=np.array(v)
a, b = np.polyfit(x, y, 1)
print("Slope=",a,"\n")
slope=math.atan(a)
r=[[math.cos(slope),math.sin(slope)],[-math.sin(slope),math.cos(slope)]]
r=np.array(r)

up=[]
down=[]
for i in range(10):
    j=v[0:2,i:i+1]
    up.append(j[0][0]*r[0][0]+j[1][0]*r[0][1])
    down.append((j[0][0]*r[1][0]+j[1][0]*r[1][1]))
v_dash=[]
v_dash.append(up)
v_dash.append(down)
v_dash=np.array(v_dash)
r_inv=[[r[0][0],r[1][0]],[r[0][1],r[1][1]]]
r_inv=np.array(r_inv)
print("r\n",r,"\n")
print("r_inv\n",r_inv,"\n")

print("v_dash\n",v_dash,"\n")

up=[]
down=[]
for i in range(10):
    j=v_dash[0:2,i:i+1]
    up.append(j[0][0]*r_inv[0][0]+0*r_inv[0][1])
    down.append((j[0][0]*r_inv[1][0]+0*r_inv[1][1]))
v_recon=[]
v_recon.append(up)
v_recon.append(down)
v_recon=np.array(v_recon)
print("v_recon\n",v_recon)

err=0
for i in range(10):
    j=v[0:2,i:i+1]
    k=v_recon[0:2,i:i+1]
    err=err+((j[0][0]-k[0][0])**2)
    err=err+((j[1][0]-k[1][0])**2)
slope_v_recon,c=np.polyfit(v_recon[0],v_recon[1],1)
print("\nSlope=",a,"\n")
print("Slope of v_recon=",slope_v_recon)
print("diff=",a-slope_v_recon)
    
print("\nrms error= ",err/14)
print("\nsquared error= ",err)