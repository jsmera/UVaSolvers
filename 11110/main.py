from sys import stdin



deltaX = [1, -1, 0, 0]
deltaY = [0, 0, 1, -1]


def main():
  n = int(input())
  while n:
    matrix = [[n for _ in range(n)] for _ in range(n)]
    visited = [[0 for _ in range(n)] for _ in range(n)]

    for group in range(1, n):
      s = [ int(i) for i in stdin.readline().strip().split() ]
      for i in range(0, len(s), 2):
        matrix[ s[i] - 1 ][ s[i+1] - 1 ] = group

    sad = False
    row = 0
    while row < n and not sad:
      colum = 0
      while colum < n and not sad:

        if visited[row][colum] == 0:
          stack = [(row, colum)]
          visited[row][colum] = 1
          division = matrix[row][colum]
          card = 1
          while len(stack):
            ux, uy = stack.pop()

            for vi in range(0, 4):
              vx = ux + deltaX[vi]
              vy = uy + deltaY[vi]
              if 0 <= vx < n and 0 <= vy < n:
                if matrix[vx][vy] == division:
                  if visited[vx][vy] == 0:
                    stack.append((vx, vy))
                    visited[vx][vy] = 1
                    card += 1
            visited[ux][uy] = 2
          if card != n:
            sad = True
        colum += 1
      row += 1

    if sad:
      print('wrong')
    else:
      print('good')


    n = int(input())

main()