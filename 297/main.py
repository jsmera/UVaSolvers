from sys import stdin
from collections import deque

class Quadtree(object):
  def __init__(self, tag):
    self.tag = tag
    self.children = []

def build(string, i):
  if string[i] == 'e' or string[i] == 'f':
    return Quadtree(string[i]), i
  else:
    tree = Quadtree(string[i])
    one, i = build(string, i+1)
    tree.children.append(one)
    two, i = build(string, i+1)
    tree.children.append(two)
    three, i= build(string, i+1)
    tree.children.append(three)
    four, i = build(string, i+1)
    tree.children.append(four)
    return tree, i

def main():
  N = int(stdin.readline().strip())
  while N:
    data_one = stdin.readline().strip()
    data_two = stdin.readline().strip()

    a, _ = build(data_one, 0)
    b, _ = build(data_two, 0)

    ans = 0
    deque_for_a, deque_for_b = deque([(a, 1)]), deque([(b, 1)])
    while len(deque_for_a) or len(deque_for_b):
      node_a = node_b = Quadtree('')
      lvl = 0
      if len(deque_for_a):
        node_a, lvl = deque_for_a.popleft()
      if len(deque_for_b):
        node_b, lvl = deque_for_b.popleft()

      if node_b.tag == 'f' or node_a.tag == 'f':
        if lvl > 6:
          ans += 1
        else:
          ans += 4**(6-lvl)
      else:
        if node_a.tag == 'p':
          for child in node_a.children:
            deque_for_a.append((child, lvl+1))
        
        if node_b.tag == 'p':
          for child in node_b.children:
            deque_for_b.append((child, lvl+1))
    
    print("There are {} black pixels.".format(ans))
    N -= 1

main()
