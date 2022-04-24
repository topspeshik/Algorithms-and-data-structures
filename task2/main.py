import sys
dict = {}
c = 0
for i in range(5):
    c = 10**i
    dict.clear()
    for j in range(c):
        dict[j] = c
    print(c, sys.getsizeof(dict), end=" ")