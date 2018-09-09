from sys import stdin, setrecursionlimit

setrecursionlimit(25000)

INF = -1
visited = None
final = None
G = None

def DFS(u):
  global visited, final, G
  visited[u] = 1
  last = True
  fist = True
  temp = None
  for v in G[u]:
    if visited[v] == 0:
      last = False
      child = DFS(v)

      if fist:
        temp = child
        fist = False
      else:
        temp = temp if child == temp else INF
    else:
      # Si ya fue visitaso pero necesito saber su
      # alcance
      if fist:
        temp = final[v]
        fist = False
      else:
        temp = temp if final[v] == temp else INF

  # Ultimo nodo alcanzable
  if last and temp == None:
    final[u] = u
    return u
  # Resto de casos
  final[u] = temp
  return temp

def main():
  global visited, final, G
  n, m = map(int, stdin.readline().strip().split())
  while n or m:
    G = [set() for _ in range(n)]
    in_degree = [0 for _ in range(n)]

    while m:
      a, b = map(int, stdin.readline().strip().split())
      if b not in G[a]:
        G[a].add(b)
      m -= 1

    # Se revisa para cada nodo cual tiene in-degree cero,
    # estos nodos seran el inicio de nuestra busqueda
    # En caso de que no exista ni uno con in-degree cero
    # el caso sera 0
    for i in range(n):
      for v in G[i]:
        in_degree[v] += 1
    
    visited = [0 for _ in range(n)]
    final = [-1 for _ in range(n)]
    dontcare = cycle = True
    u = 0
    while u < n and dontcare:
      if in_degree[u] == 0:
        cycle = False
        target = DFS(u)
        if target == -1:
          dontcare = False
      u += 1
    # Or exclusivo, no puede existir un grafo
    # con subgrafos don't care o lleno de ciclos
    ans = dontcare ^ cycle
    u = 0
    # Si un subgrafo es don't care y existe un ciclo
    # entonces el grafo completo es "care"
    missing = False
    while u < n and not missing:
      if visited[u] == 0:
        missing = True
      u += 1
    if missing:
      print("0")
    else:
      print("{}".format(int(ans)))
    n, m = map(int, stdin.readline().strip().split())

main()
