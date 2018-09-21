from sys import stdin
from math import sqrt, ceil

def main():
  a, b = map(int, stdin.readline().strip().split())
  while a and b:
    limit_a = ceil(sqrt(a))
    limit_b = int(sqrt(b))
    if limit_b < limit_a:
      print(0)
    else:
      print(abs( limit_a - limit_b ) + 1)
    a, b = map(int, stdin.readline().strip().split())

main()
