#include <cstdio>

using namespace std;

int main() {
  while (true) {
    int moths, n_res;
    double first, prestamo;
    scanf("%d %lf %lf %d", &moths, &first, &prestamo, &n_res);
    if (moths < 0)
      break;
    double rats[101];
    double devaluo = first + prestamo;
    
    for (int i = 0; i < 101; i++) {
      rats[i] = 0;
    }

    while (n_res--) {
      int n_moth;
      double rat;
      scanf("%d %lf", &n_moth, &rat);
      rats[n_moth] = rat;
    }
    devaluo-=devaluo*rats[0];
    prestamo-=first;

    int res = 1;
    double before_rat = rats[0];
    /*while (devaluo < prestamo) {
      before_rat = rats[res] == 0? before_rat: rats[res];
      devaluo -= devaluo*before_rat;
      prestamo -= first;
      res++;
    }*/
    for (int i = 0; i < 101; i++) {
      printf("%d %lf\n", i, rats[res]);
    }
    printf("%lf\n", before_rat);
  }
  return 0;
}
