
from sys import stdin, setrecursionlimit


setrecursionlimit(10000)


graph = None
visited = None
parent = None
d = None
low = None
C = None
ar_points = None


def DFS(u):
  global graph, parent, ar_points, visited, d, low, C
  
  d[u] = C
  low[u] = C
  C += 1
  visited[u] = 1
  tree = 0
  for v in graph[u]:
    if visited[v] == 0:
      parent[v] = u
      tree += 1
      DFS(v)
      low[u] = min(low[u], low[v])
      if parent[u] == -1 and tree > 1:
        ar_points[u] += 1
      
      if parent[u] != -1 and low[v] >= d[u]:
        ar_points[u] += 1

    elif parent[u] != v:
      low[u] = min(low[u], d[v])


def main():
  global graph, parent, ar_points, visited, d, low, C

  n, m = map(int, stdin.readline().strip().split())
  while n and m:
    graph = [[] for _ in range(n)]
    x, y = map(int, stdin.readline().strip().split())
    while x >= 0 and y >= 0:
      graph[x].append(y)
      graph[y].append(x)
      x, y = map(int, stdin.readline().strip().split())

    # Busqueda de puntos de articulacion con DFS
    visited = [0 for _ in range(n)]
    d = [-1 for _ in range(n)]
    low = [-1 for _ in range(n)]
    ar_points = [1 for _ in range(n)]
    parent = [-1 for _ in range(n)]
    C = 0
    
    for u in range(n):
      if visited[u] == 0:
        DFS(u)

    pigeons = []
    for i in range(n):
      pigeons.append((i, ar_points[i]))

    pigeons = sorted(pigeons,
      key=lambda item: -item[1])
    
    for i in range(m):
      print("{} {}".format(
        pigeons[i][0],
        pigeons[i][1],
      ))
    print()
    n, m = map(int, stdin.readline().strip().split())


main()
