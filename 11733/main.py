from sys import stdin

class Disjoint:
  def __init__(self, n):
    self.__p = [i for i in range(n)]
    self.__r = [0 for i in range(n)]
    self.__sizes = [1 for i in range(n)]
    self.__size = n

  def __str__(self):
    return str(self.__p)

  def __len__(self):
    return self.__size

  def find(self, i):
    if self.__p[i] == i:
      return i
    self.__p[i] = self.find(self.__p[i])
    return self.__p[i]

  def size(self, i):
    return self.__sizes[self.find(i)]

  def same(self, i, j):
    return self.find(i) == self.find(j)

  def union(self, i, j):
    x = self.find(i)
    y = self.find(j)
    if x != y:
      self.__size -= 1
      if self.__r[x] > self.__r[y]:
        self.__p[y] = x
        self.__sizes[x] += self.__sizes[y]
      else:
        self.__p[x] = y
        self.__sizes[y] += self.__sizes[x]
        if self.__r[x] == self.__r[y]:
          self.__r[y] += 1

def main():
  T = int(stdin.readline().strip())
  T_case = 1
  while T:
    N, M, A = map(int, stdin.readline().strip().split())
    edges = []
    while M:
      X, Y, C = map(int, stdin.readline().strip().split())
      edges.append((X, Y, C))
      M -= 1
    roads = sorted(edges, key = lambda road: road[2])
    D = Disjoint(N+1)
    cost_roads = 0
    for u, v, w in roads:
      if not D.same(u, v) and w < A:
        cost_roads += w
        D.union(u, v)
      if w >= A: break

    Z = len(D) - 1
    Y = cost_roads + A*Z
    print("Case #{}: {} {}".format(T_case, Y, Z))
    T_case += 1
    T -= 1

main()
