import numpy as np
import matplotlib.pyplot as plt

def f(t):
    return np.mod(t - np.pi, 3*np.pi) - np.pi

def fourier_trig(t,N):
    S = 0
    for n in range(1,N+1):
        S += 2 * (-1)**(n+1) * np.sin(n*t) / n
    return S

x = np.linspace(-6,6,1000)

y = [f(t) for t in x]
y_fourier = [fourier_trig(t,50) for t in x]

plt.plot(x,y)
plt.plot(x,y_fourier)
plt.grid(True)
plt.show()