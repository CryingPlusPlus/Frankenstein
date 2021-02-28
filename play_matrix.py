import numpy as np

a = np.matrix([
    [1, 2, 3],
    [4, 5, 6]
])

b = np.matrix([
    [7, 8],
    [9, 10],
    [11, 12]
])

c = a * b
print(c)
