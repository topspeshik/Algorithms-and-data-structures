f = open('out.txt')

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
count = 0
for line in f:
    arr = line.split()
    c = ""
    for i in range(4):
        c = c + bin(int(arr[i]))[2:]
    if arr[4] != odd(int(c)):
        count +=1

print(count)
