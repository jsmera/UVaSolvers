from sys import stdin



def main():
  N = int(input())

  chimps = [int(i) for i in stdin.readline().strip().split()]

  Q = int(input())

  Qi = [int(i) for i in stdin.readline().strip().split()]
  

  for target in Qi:
    # lower
    start = 0
    end = N-1
    low = -1

    while start <= end:
      mid = start + (end-start)//2
      if chimps[mid] == target:
        end = mid - 1
      elif chimps[mid] > target:
        end = mid - 1
      else:
        start = mid + 1
        low = mid

    # upper
    start = 0
    end = N-1
    upper = -1

    while start <= end:
      mid = start + (end-start)//2

      if chimps[mid] == target:
        start = mid + 1
      elif chimps[mid] > target:
        upper = mid
        end = mid - 1
      else:
        start = mid + 1

    ans1 = chimps[low] if low != -1 else 'X'
    ans2 = chimps[upper] if upper != -1 else 'X'
    print("{} {}".format(ans1, ans2))

main()
