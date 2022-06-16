import math

i = -2 * math.pi
while(i < 2*math.pi):
    i += 0.01
    i = round(i, 2)
    num = math.sin(2*i) + math.cos(i/2)
    print(str(i) + " " + str(num))

