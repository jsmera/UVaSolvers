from sys import stdin

tree = ""
I = 0

def in_order():
  global tree, I
  if tree[I] == '(':
    I += 1
    l = in_order() # Left
    op = tree[I]
    I += 1
    r = in_order() # Right
    I += 1
    if op == '+': return l + r
    elif op == '-': return l - r
    elif op == '*': return l * r
    else: return l / r
  else:
    temp = float(tree[I])
    I += 1
    return temp

def main():
  global tree, I
  T = int(stdin.readline().strip())
  while T:
    I = 0
    tree = stdin.readline().strip().split()
    print("{0:.2f}".format(in_order()))
    T -= 1

main()
