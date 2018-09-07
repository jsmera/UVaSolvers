from sys import stdin
from collections import deque



def main():
  T = int(input())
  tcase = 1
  while T:
    N, M = map(int, stdin.readline().strip().split())
    visited = [False for _ in range(N+1)]
    graph = [[] for _ in range(N+1)]
    graph_r = [[] for _ in range(N+1)]
    while M:
      a, b = map(int, stdin.readline().strip().split())
      graph[a].append(b)
      graph_r[b].append(a)
      M -= 1

    # Kosaraju's Algorithm
    # DFS para hacer la lista para identificar componentes
    # print("A")
    L = deque()
    for u in range(1, N+1):
      if not visited[u]:
        stack = [u]
        aux = [u]
        visited[u] = True
        while len(stack):
          # print("A")
          w = stack.pop()
          for v in graph[w]:
            # print("A")
            if not visited[v]:
              stack.append(v)
              aux.append(v)
              visited[v] = True
        while len(aux):
          L.append(aux.pop())

    # Identificacion y agrupamiento de componentes
    # Conteo de nodos "desencadenadores" por componentes
    C = 0
    scc = [-1 for _ in range(N+1)]
    while len(L):
      u = L.pop()
      if scc[u] == -1:
        stack = [u]
        scc[u] = C
        while len(stack):
          w = stack.pop()
          for v in graph_r[w]:
            if scc[v] == -1:
              stack.append(v)
              scc[v] = C
        C += 1
    
    # Verificacion por cada componente cuantos puede
    # "prender" este si son diferentes, en caso de que
    # un componente no pueda ser prendido por otro
    # signigica que tendre que prender ese
    trigger = [0 for _ in range(C)]
    for u in range(1, N+1):
      for v in graph[u]:
        if scc[u] != scc[v]:
          trigger[scc[v]] += 1

    count = 0
    for i in range(C):
      if trigger[i] == 0:
        count += 1;
    print("Case {}: {}".format(tcase, count))
    tcase += 1
    stdin.readline()
    T -= 1


main()
