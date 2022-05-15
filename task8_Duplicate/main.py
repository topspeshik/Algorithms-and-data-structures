import random
import time


def R(letter):
    random.seed(1)
    dictLetters = {}
    for i in range(127):
        dictLetters[i] = random.randint(0, 10000)
    return dictLetters[letter]


def CRC(word):
    h = 0
    for i in range(len(word)):
        ki = int(ord(word[i]))
        highorder = h & 0xf8000000
        h = h << 5
        h = h ^ (highorder >> 27)
        h = h ^ ki
    return h


def PJW(word):
    h = 0
    for i in range(len(word)):
        ki = int(ord(word[i]))
        h = (h << 4) + ki
        g = h & 0xf0000000
        if g != 0:
            h = h ^ (g >> 24)
            h = h ^ g
    return h

def BUZ(word):
    h = 0
    for i in range(len(word)):
        ki = int(ord(word[i]))
        highorder = h & 0x80000000
        h = h << 1
        h = h ^ (highorder >> 31)
        h = h ^ R(ki)
    return h


def find_duplicates(hash_function):
    start_time = time.time()

    dictFiles = {}
    for i in range(500):
        f = open(f'out/{i}.txt')
        word = f.read().replace(" ", "").replace("\n","")
        h = hash_function(word)
        dictFiles[h] = i

    print(time.time() - start_time, "seconds" + str(hash_function))
    print(500 - len(dictFiles), "Duplicate count")

    return dictFiles

find_duplicates(hash)
find_duplicates(CRC)
find_duplicates(PJW)
find_duplicates(BUZ)


