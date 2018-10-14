from sys import stdin

board,lenb,lenc = None,None,None
deltar = [-1,-1,-1,0,0,1,1,1]
deltac = [-1,0,1,-1,1,-1,0,1]

visited = None

def dfs(row,col):
    global visited
    stack = [ (row,col) ] ; visited[row][col] = 1
    while len(stack) != 0:
        r,c = stack.pop()
        for i in range (len(deltar)):
            dr,dc = r+deltar[i],c+deltac[i]
            if (0 <= dr < lenb and 0 <=dc<lenb and board[dr][dc] == '1' and visited[dr][dc] == 0):
                stack.append((dr,dc)) ; visited[dr][dc] = 1
        visited[r][c] = 2


def solve():
    global board,lenb,lenc,visited
    visited = [[0 for _ in range(lenb)] for _ in range(lenb)]
    ans = 0
    for r in range(lenb):
        for c in range(lenb):
            if board[r][c] == '1' and visited[r][c] == 0:
                ans += 1
                dfs(r,c)
    return ans

def main():
    global board,lenb,lenc
    line = stdin.readline()
    tc = 1
    while (len(line) != 0):
        lenb = int(line)
        board = list()
        for i in range(lenb):
            board.append(stdin.readline().strip())
        print('Image number {0} contains {1} war eagles.'.format(tc,solve()))
        line = stdin.readline()
        tc += 1
main()
