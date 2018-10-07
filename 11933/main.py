from sys import stdin

def countBits(n):
  count = 0
  while (n): 
    count += 1
    n >>= 1
  return count

def main():
  n = int(stdin.readline().strip())
  while n:
    a = b = i = 0
    j = 1
    limit = countBits(n)
    while i <= limit:
      if n & (1<<i):
        if j%2 != 0:
          a |= (1<<i)
        else:
          b |= (1<<i)
        j += 1
      i += 1
    print("{} {}".format(a, b))
    n = int(stdin.readline().strip())

main()
