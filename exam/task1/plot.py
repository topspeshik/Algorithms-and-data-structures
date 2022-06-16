import matplotlib.pyplot as plt

arrX = []
arrY = []
data = input().split()
while(data):
    arrX.append(float(data[0]))
    arrY.append(float(data[1]))
    
    try:
        data = input().split()
    except:
        break

plt.plot(arrX,arrY)
plt.show()



