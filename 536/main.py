from sys import stdin, setrecursionlimit

setrecursionlimit(10000)

preord = inord = ""

def build(preord, inord):
  # Caso base
  if len(inord) == 1:
    print(preord[0], end='')
  elif len(inord) > 1:
    i = inord.index(preord[0])
    build(preord[1:i+1], inord[:i])
    build(preord[i+1:], inord[i+1:])
    print(preord[0], end='')

def main():
  global preord, inord
  trees = stdin.readline().strip()
  while len(trees):
    preord, inord = trees.split()
    build(preord, inord)
    print()
    trees = stdin.readline().strip()

main()
