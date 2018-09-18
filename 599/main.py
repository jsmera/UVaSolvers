from sys import stdin


class Disjoint:
  def __init__(self, n):
    self.p = [i for i in range(n)]
    self.r = [0 for i in range(n)]
    self.sizeSets = [1 for i in range(n)]
    self.size = n


  def find(self, i):
    if self.p[i] == i:
      return i
    else:
      self.p[i] = self.find(self.p[i])
      return self.p[i]

  def sameSet(self, i, j):
    return self.find(i) == self.find(j)

  def sizeOfSet(self, i):
    return self.sizeSets[self.find(i)]

  def union(self, i, j):
    if not self.sameSet(i, j):
      self.size -= 1
      x = self.find(i)
      y = self.find(j)
      if self.r[x] > self.r[y]:
        self.p[y] = x
        self.sizeSets[x] += self.sizeSets[y]
      else:
        self.p[x] = y
        self.sizeSets[y] += self.sizeSets[x]
        if self.r[x] == self.r[y]:
          self.r[y] += 1

def decode(letter):
  return ord(letter) - 65;

def main():
  T = int(stdin.readline().strip())
  while(T):
    forest = Disjoint(26)
    line = stdin.readline().strip()
    while line[0] != "*":
      u = decode(line[1])
      v = decode(line[3])
      forest.union(u, v)
      line = stdin.readline().strip()
    nodes = stdin.readline().strip().split(",")
    maxU = -1
    printed = [False for _ in range(26)]
    trees = acorns = 0
    for i in nodes:
      u = decode(i)
      root = forest.find(u)
      if not printed[root]:
        if forest.sizeOfSet(root) > 1:
          trees += 1
        else:
          acorns += 1
        printed[root] = True
    print("There are {} tree(s) and {} acorn(s).".format(trees, acorns))
    T -= 1

main()
