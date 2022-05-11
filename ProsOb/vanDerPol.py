import numpy as np
import matplotlib.pyplot as plt

def f(x,y):
    return y

def g(x,y,my):
    return my*(1-x**2)*y-x

def symplektisk(f,g,x0,y0,h,my):
    x = [x0]
    y = [y0]
    for i in range(5000000):
        x.append(x[i] + h*f(x[i],y[i]))
        y.append(y[i] + h*g(x[i+1],y[i],my)) 
    return x,y

my = .02
h = 0.001

x1, y1 = symplektisk(f,g,-.4,4,h,my)

#Faseplan
x = np.arange(-4,5)
y = np.arange(-4,5)

X,Y = np.meshgrid(x,y)

U = f(X,Y)
V = g(X,Y,my)

plt.streamplot(X,Y,U,V, density = 1)
plt.plot(x1,y1)
plt.grid(True)
plt.legend()
plt.show()