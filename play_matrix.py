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

# c = a * b
# print(c)

class NN:
    def __init__(self):
        self.w = [
            np.matrix([
                [1, 2, 3, 4],
                [1, 2, 3, 4],
                [1, 2, 3, 4]
            ]),
            np.matrix([
                [1, 2, 3],
                [1, 2, 3],
                [1, 2, 3],
                [1, 2, 3]
            ]),
            np.matrix([
                [1, 2, 3, 4]
            ])
        ]

    def y(self, X, l = 2):
        if l == 0:
            return self.w[0] * X
        else:
            return self.w[l] * self.y(X, l - 1)

n = NN()

X = np.matrix([
    [1],
    [2],
    [3],
    [4],
])

print(n.y(X))
