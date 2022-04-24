import sys

import matplotlib.pyplot as plt
import time

lst = []
t = time.perf_counter()
for i in range(10**5):
    lst.append(i)
print(f"Скорость заполнения {time.perf_counter() - t}")
print(f"Память {sys.getsizeof(lst)}")

data = input().split()

x = list(map(int, data[::2]))
y = list(map(int, data[1::2]))

plt.figure()
plt.subplot()
plt.plot(x, y)

plt.show()