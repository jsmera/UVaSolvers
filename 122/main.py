from collections import deque
from sys import stdin

class Tree(object):
  def __init__(self, value = -1, left = None, right = None):
    self.value = value 
    self.left = left
    self.right = right

def main():
  line = stdin.readline().strip()
  while len(line):
    data = line.split()
    tree = Tree()
    condition = True
    i = 0
    while condition and i < len(data)-1:
      pair = data[i].split(",")
      index = tree
      for j in pair[1][:len(pair[1])-1]:
        if j == "L":
          if index.left == None:
            index.left = Tree()
          index = index.left
        else:
          if index.right == None:
            index.right = Tree()
          index = index.right
      if index.value != -1:
        condition = False
      else:
        index.value = pair[0][1:]
      i += 1

    stack, aux = deque([tree]), deque()
    while condition and len(stack):
      u = stack.popleft()
      # print(u.value)
      aux.append(u.value)
      if u.left != None or u.right != None:
        if u.value == -1:
          condition = False
          continue
      if u.left != None:
        stack.append(u.left)
      if u.right != None:
        stack.append(u.right)

    if not condition:
      print("not complete")
    else:
      for i in range(len(aux)):
        if i != len(aux)-1:
          print(aux[i], end=" ")
        else:
          print(aux[i])
    line = stdin.readline().strip()

main()