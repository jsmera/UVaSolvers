#include <cstdio>

int main() {
  int T, c = 1;
  scanf("%d\n", &T);
  while(T--) {
    int N, res = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      int temp;
      scanf("%d", &temp);
      if (temp > res) {
        res = temp;
      }
    }
    printf("Case %d: %d\n", c++, res);
  }

  return 0;
}