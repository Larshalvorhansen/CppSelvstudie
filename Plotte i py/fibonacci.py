a, b = 0, 1
teller = 0

while teller < 100:
    print(a)
    c = a + b
    a = b
    b = c
    teller += 1