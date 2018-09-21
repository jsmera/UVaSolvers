from collections import deque
from sys import stdin

def left(p):
  return p << 1

def right(p):
  return (p << 1) + 1

def main():
  line = stdin.readline().strip()
  while len(line):
    tree = line.split()
    binary = [-1 for _ in range(1000000)]
    condition = True
    i = 0
    maxIndex = -1
    while condition and i < len(tree)-1:
      pair = tree[i].split(",")
      index = 1
      for j in pair[1][:len(pair[1])-1]:
        if j == "L":
          index = left(index)
        else:
          index = right(index)
      if binary[index] != -1:
        condition = False
      else:
        if index > maxIndex:
          maxIndex = index
        binary[index] = int(pair[0][1:])
      i += 1

    stack, aux = deque([1]), deque()
    while condition and len(stack):
      u = stack.popleft()
      if binary[u] != -1:
        aux.append(u)
      v1 = left(u)
      v2 = right(u)
      if v1 <= maxIndex or v2 <= maxIndex:
        if binary[v1] != -1 or binary[v2] != -1:
          if binary[u] == -1:
            condition = False
            continue
        stack.append(v1)
        stack.append(v2)

    if not condition:
      print("not complete")
    else:
      for i in aux:
        print(binary[i], end=" ")
      print()
    line = stdin.readline().strip()

main()