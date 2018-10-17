from sys import stdin

INF = float('inf')
adjacent = [(1, 0), (-1, 0), (0, 1), (0, -1)]

class Disjoint:
  def __init__(self, n):
    self.__p = [i for i in range(n)]
    self.__r = [0 for i in range(n)]
    self.__breached = [False for i in range(n)]
    self.__size = n

  def __len__(self):
    return self.__size

  def find(self, i):
    if self.__p[i] == i:
      return i
    self.__p[i] = self.find(self.__p[i])
    return self.__p[i]

  def is_breached(self, i):
    return self.__breached[i]

  def breach(self, i):
    self.__breached[i] = True

  def same(self, i, j):
    return self.find(i) == self.find(j)

  def union(self, i, j):
    x = self.find(i)
    y = self.find(j)
    if x != y:
      self.__size -= 1
      if self.__r[x] > self.__r[y]:
        self.__p[y] = x
      else:
        self.__p[x] = y
        if self.__r[x] == self.__r[y]:
          self.__r[y] += 1

def row_major_order(M, n, m):
  return M*n + m + 1

def main():
  line = stdin.readline().strip()
  while len(line):
    r, c, s = map(int, line.split())
    shield = Disjoint(r*c+2)
    
    aliens = 0
    nostalgia = r*c+1
    
    next_breached_up = [ -1 for _ in range(c)]
    next_breached_down = [ INF for _ in range(c)]
    
    for i in range(r):
      table = stdin.readline().strip()
      for j in range(c):
        if table[j] == '.':
          key = row_major_order(c, i, j)
          shield.breach(key)
          if i == 0:
            shield.union(key, aliens)
          if i+1 == r:
            shield.union(key, nostalgia)

          for delta_i, delta_j in adjacent:
            new_i = i + delta_i
            new_j = j + delta_j
            if 0 <= new_i < r and 0 <= new_j < c:
              adjacent_key = row_major_order(c, new_i, new_j)
              if shield.is_breached(adjacent_key):
                shield.union(key, adjacent_key)
        else:
          next_breached_up[j] = max(i, next_breached_up[j])
          next_breached_down[j] = min(i, next_breached_down[j])
    k = 0
    while k < s and not shield.same(aliens, nostalgia):
      a = int(stdin.readline().strip())
      found = False
      j = abs(a)-1
      # Get and update next shot
      if a < 0:
        i = next_breached_up[j]
        aux = i-1
        while 0 <= aux < i and shield.is_breached(row_major_order(c, aux, j)):
          aux -= 1
        next_breached_up[j] = aux
      else:
        i = next_breached_down[j]
        aux = i+1
        while i < aux < r and shield.is_breached(row_major_order(c, aux, j)):
          aux += 1
        next_breached_down[j] = aux
      shot = row_major_order(c, i, j)
      shield.breach(shot)
      if i == 0:
        shield.union(shot, aliens)
      if i+1 == r:
        shield.union(shot, nostalgia)
      for delta_i, delta_j in adjacent:
        new_i = i + delta_i
        new_j = j + delta_j
        if 0 <= new_i < r and 0 <= new_j < c:
          adjacent_key = row_major_order(c, new_i, new_j)
          if shield.is_breached(adjacent_key):
            shield.union(shot, adjacent_key)
      k += 1
    
    for _ in range(s-k):
      stdin.readline()

    if shield.same(aliens, nostalgia):
      if k > 0:
        print("{}{}".format("-" if a < 0 else "", k))
      else:
        print("0")
    else:
      print("X")

    line = stdin.readline().strip()

main()
