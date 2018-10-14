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


def main():
  T = int(stdin.readline().strip())
  stdin.readline()
  while T:
    N = int(stdin.readline().strip())
    network = Disjoint(N+1)
    successfully = unsuccessfully = 0
    line = stdin.readline().strip().split()
    while len(line):
      if line[0] == 'c':
        network.union(int(line[1]), int(line[2]))
      else:
        if network.sameSet(int(line[1]), int(line[2])):
          successfully += 1
        else:
          unsuccessfully += 1
      line = stdin.readline().strip().split()
    print("{},{}".format(successfully, unsuccessfully))
    if T != 1:
      print()
    T -= 1

main()
