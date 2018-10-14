from sys import stdin
from heapq import heappush, heappop

INF = float('inf')

def main():
  C = int(stdin.readline().strip())
  stdin.readline().strip()

  while C:
    N = int(stdin.readline().strip())
    E = int(stdin.readline().strip())
    T = int(stdin.readline().strip())
    M = int(stdin.readline().strip())
    maze = [ [] for _ in range(N+1)]
    while M:
      a, b, w = map(int, stdin.readline().strip().split())
      maze[b].append((a, w))
      M -= 1

    # Dijkstra
    distance = [ INF for i in range(N+1)]
    distance[E] = 0
    heap = [(E, 0)]
    while len(heap):
      u, w = heappop(heap)
      for v, wi in maze[u]:
        alt = w + wi
        if alt < distance[v]:
          distance[v] = alt
          heappush(heap, (v, alt))
    ans = 0
    for i in range(N+1):
      if distance[i] <= T:
        ans += 1
    if C > 1:
      print(ans, end='\n\n')
    else:
      print(ans)
    stdin.readline().strip()
    C -= 1

main()
