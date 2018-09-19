from sys import stdin, setrecursionlimit

setrecursionlimit(10000)
tree = []

# lo is the root
def post(lo, hi):
  if hi > lo:
    mid = -1
    i = lo
    while mid == -1 and i <= hi:
      if tree[i] > tree[lo]:
        mid = i
      i += 1
    if mid != -1:
      post(lo+1, mid-1)
      post(mid, hi)
      print(tree[lo])
    else:
      post(lo+1, hi)
      print(tree[lo])
  elif lo == hi:
    print(tree[lo])

def main():
  global tree
  n = stdin.readline().strip()
  while len(n):
    tree.append(int(n))
    n = stdin.readline().strip()
  post(0, len(tree)-1)

main()
