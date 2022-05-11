import numpy as np
import matplotlib.pyplot as plt

plt.figure()

N=200
h=.1

t=np.zeros(N+1)
y=np.zeros(N+1)
z=np.zeros(N+1)

y[0]=2
z[0]=2

for i in range(N):
    y[i+1]=y[i]-h*y[i]*(1-z[i])
    z[i+1]=z[i]-h*z[i]*(y[i+1]-1)
    t[i+1]=t[i]+h
    
plt.plot(y,z)