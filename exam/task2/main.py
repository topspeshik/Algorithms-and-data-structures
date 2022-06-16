def odd(arr):
    c = 0
    for i in range(len(arr)):
        if int(arr[i]) == 1:
            c += 1
    return c % 2

def funHash(word):
    result = []
    res = ""
    bitOdd = []
    for j in range(len(word)):
        for i in range(0, 8, 2):
            bitOdd.append(bin(int(ord(word[j])) >> 7 - i & 1)[2:])
        if len(result) == 16:
            result.pop(0)
            result.append(odd(bitOdd))
        else:
            result.append(odd(bitOdd))
        bitOdd.clear()

    for i in range(len(result)):
        res += str(result[i])

    res = int(res, 2)
    return res



f = open('words.txt')

words = f.read().split()

hashs = []

lenWords = len(words)

for i in range(lenWords):
    hashs.append(funHash(words[i]))

dictWords = {}
for i in range(lenWords):
    dictWords[hashs[i]] = i


print(lenWords - len(dictWords))

f.close()




