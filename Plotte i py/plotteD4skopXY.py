import csv
import matplotlib.pyplot as plt

header = []
data = []


filename = "D4dataScope.csv"
with open(filename) as csvfile:
    csvreader = csv.reader(csvfile)

    header = next(csvreader)

    for datapoint in csvreader:

        values = [float(value) for value in datapoint]
        data.append(values)

print(header)
print(data[0])
print(data[1])

time = [p[0] for p in data]
ch1 = [p[1] for p in data]
ch2 = [p[2] for p in data]

plt.xlabel("Amplitude Ch1(V)")
plt.ylabel("Amplitude Ch2(V)")
plt.plot(ch1,ch2)
plt.show()

    
