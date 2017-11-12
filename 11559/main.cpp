#include <cstdio>

int main() {
  int N, B, H, W;
  while (scanf("%d %d %d %d\n", &N, &B, &H, &W) != EOF ) {
    int res = -1;
    for (int i = 0; i < H; i++) {
      int priceH, beds;
      scanf("%d\n", &priceH);
      for (int i = 0; i < W; i++) {
        scanf("%d", &beds);
        if (N*priceH <= B && N <= beds) {
          res = N*priceH < res || res == -1 ? N*priceH: res;
        }
      }
    }
    if (res < 0)
      printf("stay home\n");
    else
      printf("%d\n", res);
  }

  return 0;
}
