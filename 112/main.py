from sys import stdin, setrecursionlimit

setrecursionlimit(10000)

INPUT, I = stdin.buffer.read(), 0
SPACE = ord(' ')
CR = ord('\n')
CR2 = ord('\r')
LESS = ord('-')
R = ')'
L = '('

def isDigit():
  return 48 <= INPUT[I] <= 57

def isLess():
  return INPUT[I] == LESS

def read_blanks():
  global INPUT, I
  while I < len(INPUT) and (INPUT[I] == SPACE or INPUT[I] == CR2 or INPUT[I] == CR):
    I += 1

def read_par():
  global INPUT, I
  ans, I = chr(INPUT[I]), I+1
  return ans

def read_num():
  global INPUT, I
  ans = 0
  while I < len(INPUT) and isDigit():
    ans, I = int(chr(INPUT[I])) + ans*10, I+1
  return ans

def next_token():
  global I
  ans = None
  read_blanks()
  if I != len(INPUT):
    if isLess():
      I += 1
      ans = -1*read_num()
    elif isDigit():
      ans = read_num()
    else:
      ans = read_par()
  return ans

def search(v, goal):
  a = next_token()
  b = next_token()
  # Caso base
  if a == L and b == R:
    return 2
  else:
    n_l = 0
    n_r = 0 
    # a is (
    # b has root
    l = search(v+b, goal)
    r = search(v+b, goal)
    # it ate the last )
    next_token()
    if l == 2 and r == 2:
      return 1 if v + b == goal else 0
    return l == 1 or r == 1

def main():
  global INPUT, L
  tkn = next_token()
  while tkn != None:
    res = search(0, tkn)
    print("yes" if res == 1 else 'no')
    tkn = next_token()

main()
