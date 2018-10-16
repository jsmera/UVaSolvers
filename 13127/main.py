from sys import stdin
from heapq import heappush, heappop
INF = float('inf')

def main():
  line = stdin.readline().strip()
  while len(line):
    N, M, B, P = map(int, line.split())
    city = [[] for _ in range(N)]
    while M:
      U, V, T = map(int, stdin.readline().strip().split())
      city[U].append((V, T))
      city[V].append((U, T))
      M -= 1
    banks = []
    for i in stdin.readline().strip().split():
      banks.append(int(i))
    banks.sort()
    heap = []
    if P:
      for i in stdin.readline().strip().split():
        heappush(heap, (int(i), 0))
    distance = [INF for _ in range(N)]
    # Dijkstra
    while len(heap):
      u, wi = heappop(heap)
      for v, w in city[u]:
        if wi + w < distance[v]:
          distance[v] = wi + w
          heappush(heap, (v, wi + w))
    S = 0
    E = -1
    for i in banks:
      if E < distance[i]: E = distance[i] ; S = 1
      elif E == distance[i]: S += 1
    print("{} {}".format(S, E if E != INF else "*"))
    
    for i in banks:
      if E == distance[i]:
        S -= 1
        if S:
          print("{}".format(i), end=' ')
        else:
          print("{}".format(i))
          break
    line = stdin.readline().strip()

main()
