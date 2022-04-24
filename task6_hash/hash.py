def odd(value):
  sum = 0
  value = int(value)
  while value > 0:
      sum += value % 10
      value //= 10
  if sum % 2 == 0:
    return '0'
  else:
    return '1'
  
def hash(symb):
    result = ""
    bits = ""
    for i in range(8):
        for j in range(len(symb)):
            bits = bits + bin(ord(symb[j]) >> (7 - i) & 1)[2:]
        result = result + odd(bits)
        bits = ""
    return result


symb = "asdqwerty"

print("Строка: ", symb)
print(hash(symb))







