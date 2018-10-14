from sys import stdin

class Disjoint:
  def __init__(self, n):
    self.__p = [i for i in range(n)]
    self.__r = [0 for i in range(n)]
    self.__components = [0 for i in range(n)]
    self.__sizes = [1 for i in range(n)]
    self.__size = n

  def find(self, i):
    if self.__p[i] == i:
      return i
    self.__p[i] = self.find(self.__p[i])
    return self.__p[i]

  def size(self, i):
    return self.__sizes[self.find(i)]

  def same(self, i, j):
    return self.find(i) == self.find(j)

  def components(self, i):
    return self.__components[self.find(i)]

  def union(self, i, j):
    x = self.find(i)
    y = self.find(j)

    if x != y:
      if self.__r[x] > self.__r[y]:
        self.__p[y] = x
        self.__components[x] += 1
        self.__sizes[x] += self.__sizes[y]
      else:
        self.__p[x] = y
        self.__components[y] += 1
        self.__sizes[y] += self.__sizes[x]
        if self.__r[x] == self.__r[y]:
          self.__r[y] += 1
    else:
      self.__components[x] += 1

def main():
  line = stdin.readline().strip().split()
  while len(line):
    D = Disjoint(100001)
    refusals = 0
    while len(line) > 1:
      A, B = map(int, line)
      if D.same(A, B):
        refusals += 1
      else:
        D.union(A, B)
      line = stdin.readline().strip().split()
    stdin.readline()
    line = stdin.readline().strip().split()
    print(refusals)

main()
