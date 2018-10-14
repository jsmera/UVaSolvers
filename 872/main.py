from sys import stdin
import bisect

is_dag = False

def allTopos(G, res, V, visited, in_degree):
  global is_dag
  flag = False

  for i in V:
    if in_degree[i] == 0 and not visited[i]:
      for j in G[i]:
        in_degree[j] -= 1
      
      res.append(i)
      visited[i] = True
      allTopos(G, res, V, visited, in_degree)

      res.pop()
      visited[i] = False
      for j in G[i]:
        in_degree[j] += 1
      flag = True

  if not flag:
    if len(res) == len(V):
      is_dag = True
      for i in range(len(res)):
        if i != len(res) - 1: print(chr(res[i]+65), end=" ")
        else: print(chr(res[i]+65)) 

def main():
  global is_dag
  T = int(stdin.readline().strip())
  while T:
    stdin.readline()
    is_dag = False
    G = [[] for _ in range(26)]
    in_degree = [0 for _ in range(26)]
    visited = [False for _ in range(26)]
    V = []
    for i in stdin.readline().strip().split():
      bisect.insort(V, ord(i)-65) 
    for i in stdin.readline().strip().split():
      if i[1] == '<':
        bisect.insort(G[ord(i[0])-65], ord(i[2])-65)
        in_degree[ord(i[2])-65] += 1
      else:
        bisect.insort(G[ord(i[2])-65], ord(i[0])-65)
        in_degree[ord(i[0])-65] += 1
    allTopos(G, [], V, visited, in_degree)
    if not is_dag:
      print("NO")
    if T != 1:
      print()
    T -= 1

main()
