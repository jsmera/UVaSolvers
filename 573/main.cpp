#include <stdio.h>

int main() {
  int H, U, D, F;
  while (scanf("%d %d %d %d\n", &H, &U, &D, &F), (H || U || D || F)) {
    int days = 1;
    double initial = 0, path_before = U, path_pre = path_before, path_final = U;
    path_final -= D;
    while (path_pre <= H && path_final >= 0) {
      initial = path_final;
      path_before = path_before - U*(double)F/100 < 0 ? 0 : path_before - U*(double)F/100;
      path_pre = initial + path_before;
      path_final = initial + path_before - D;
      days++;
    }
    if (path_final < 0) {
      printf("failure on day %d\n", days);
    } else if (path_pre > H) {
      printf("success on day %d\n", days);
    }
  }

  return 0;
}