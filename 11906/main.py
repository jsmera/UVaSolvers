from sys import stdin



posibilities = [(1, 1), (-1, -1),
(-1, 1), (1, -1)]


def main():
  n = int(stdin.readline().strip())
  tcase = 1
  while n:
    data = [int(x) for x in stdin.readline().strip().split()]
    R = data[0]; C = data[1]
    M = data[2]; N = data[3]
    w = int(stdin.readline().strip())
    
    board = [[0 for _ in range(C)] for _ in range(R)]
    
    while w:
      water = [int(x) for x in stdin.readline().strip().split()]
      board[water[0]][water[1]] = 2
      w -= 1

    stack = [(0, 0)]
    board[0][0] = 1
    mark = False
    even, odd  = 0, 0
    while len(stack):
      u1, u2 = stack.pop()
      ki = 0
      neighbors = []
      if M == 0 or N == 0:
        neighbors.append((u1+M,u2+N))
        neighbors.append((u1+N,u2+M))
        neighbors.append((u1-M,u2-N))
        neighbors.append((u1-N,u2-M))
      elif M == N:
        for i in posibilities:
          neighbors.append((u1+i[0]*M, u2+i[1]*N))
      else:
        for i in posibilities:
          neighbors.append((u1+i[0]*M, u2+i[1]*N))
          neighbors.append((u1+i[1]*N, u2+i[0]*M))
      for v in neighbors:
        if 0 <= v[0] < R and 0 <= v[1] < C:
          if board[v[0]][v[1]] != 2:
            if board[v[0]][v[1]] == 0:
              stack.append(v)
              board[v[0]][v[1]] = 1
              if not mark:
                mark = True
            ki += 1
      if ki != 0:
        if ki % 2 == 0: even += 1
        else: odd += 1
    if mark:
      print("Case {}: {} {}".format(tcase, even, odd))
    else:
      print("Case {}: {} {}".format(tcase, 1, 0))
    n -= 1
    tcase += 1

main()
