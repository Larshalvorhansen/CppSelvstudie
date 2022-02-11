import math

denneData = [0.5,0.34,0.48,0.97,0.42,0.08]

def varianceAndMore(data):
    # Number of observations
    n = len(data)
    # Mean of the data
    mean = sum(data) / n
    # Square deviations
    deviations = [(x - mean) ** 2 for x in data]
    # Variance
    variance = sum(deviations) / (n-1)

    standardDeviation = math.sqrt(variance)

    return (n, mean, variance, standardDeviation)

print("n, gjennomsnitt, varianse, Standardavvik: ",varianceAndMore(denneData))