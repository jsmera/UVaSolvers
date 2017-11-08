#include <cstdio>

using namespace std;

int main() {
  while (true) {
    int moths, n_res;
    double first, prestamo, rats[101];
    scanf("%d %lf %lf %d\n", &moths, &first, &prestamo, &n_res);
    if (moths < 0)
      break;

    for (int i = 0; i <= moths; i++) {
      rats[i] = 0;
    }

    while (n_res--) {
      int n_moth;
      double rat;
      scanf("%d %lf\n", &n_moth, &rat);
      rats[n_moth] = rat;
    }

    double before_rat = rats[0], pago = prestamo/moths;
    double temp = prestamo, devaluo = prestamo + first;
    devaluo -= devaluo*rats[0];
    int res = 0;

    while (devaluo < temp) {
      res++;
      if (rats[res] != 0)
        before_rat = rats[res];
      devaluo -= devaluo*before_rat;
      temp -= pago;
    }
    if (res > 1 || res == 0)
      printf("%d months\n", res);
    else
      printf("%d month\n", res);
  }
  return 0;
}
