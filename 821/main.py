from sys import stdin
from heapq import heappush, heappop
from functools import reduce

INF = float('inf')

def main():
  line = stdin.readline().strip()
  t_case = 1
  
  while len(line) > 3:
    line = line.split()
    max_node = -1
    V = set()
    # navegation = [[ INF for _ in range(101)] for _ in range(101)]
    graph = [[] for _ in range(101)]
    for i in range(0, len(line)-2, 2):
      a = int(line[i])
      b = int(line[i+1])
      V.add(a)
      V.add(b)
      max_node = max(max_node, a, b)
      graph[a].append((b, 1))
      # navegation[a][b] = 1

    path = 0
    for s in V:
      distances = [INF for _ in range(max_node+1)]
      heap = [(s, 0)]
      distances[s] = 0
      while len(heap):
        u, d = heappop(heap)
        for v, di in graph[u]:
          if distances[v] > d + di:
            distances[v] = d + di
            heappush(heap, (v, d + di))
      for i in distances:
        if i != INF: path += i
    # for i in V:
    #   navegation[i][i] = 0
    
    # for k in V:
    #   for i in V:
    #     for j in V:
    #       if navegation[i][j] > navegation[i][k] + navegation[k][j]:
    #         navegation[i][j] = navegation[i][k] + navegation[k][j]
    # path = 0
    n = len(V)*(len(V)-1)
    # for u in V:
    #   for v in V:
    #     if u != v and navegation[u][v] != INF:
    #       path += navegation[u][v]
    average = path/n
    print("Case {}: average length between pages = {:.3f} clicks".format(t_case, average))
    t_case += 1
    line = stdin.readline().strip()

main()
