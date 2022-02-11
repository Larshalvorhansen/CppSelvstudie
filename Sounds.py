from math import cos, pi
import numpy as np
from matplotlib import pyplot as plt
import wave
import struct

frequencies = [400, 600]
sample_rate = 44100
file = "Frederik.wav"
A = 500
tau = 2 * pi
f = lambda t: int(A * sum(cos(tau * freq * t) for freq in frequencies))
values = []
timesteps = []

def plot(f, t0, t1, filename):
    global values, timesteps
    timesteps = np.linspace(t0, t1, int((t1 - t0) * sample_rate))
    values = [f(t) for t in timesteps]

    with wave.open(filename,'wb') as file:
        # Documentation : https://www.tutorialspoint.com/read-and-write-wav-files-using-python-wave
        
        file.setframerate(sample_rate)
        file.setnchannels(1)
        file.setsampwidth(2)
        print(f"\nWriting values to wav-file:\nThe function has the following frequencies: {frequencies} Hz\nThe length is set to: {t1 - t0} s")
        for value in (values):
            value = struct.pack("<h", value)
            file.writeframesraw(value)
    """
    Plotting the waveform
    """
    # plt.plot(timesteps, values)
    # plt.show()


def fourier_transform(values, timesteps, n, m, freq_max):
    g = lambda t, freq: cos(tau * freq * t)
    freqs = np.linspace(0, freq_max, n)
    l = np.linspace(0, len(values) - 1, m).astype(int)
    final = []
    print("Calculating fourier transform:")
    for freq in (freqs):
        total = 0
        for i in l:
            total += values[i] * g(timesteps[i], freq)
        final.append(total / m)
    plt.plot(freqs, final)
    plt.ylim(0, 300)
    plt.show()

plot(f, 0, 2, file)
fourier_transform(values, timesteps, 2000, 5000, 700)