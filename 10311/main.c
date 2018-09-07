#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"


#define MAX 100000000

bool core [100000001];
int primes [5761456];

void sieve() {
  int i, index = 0;
  int limit = (int) sqrt(MAX);
  for (i = 2; i <= limit; i++) {
    if ( !core[i] ) {
      int j;
      for (j = i; j <= (int)(MAX/i); j++ ) {
        core[j*i] = true;
      }
    }
  }

  for (i = 2; i <= MAX; i++) {
    if (!core[i]) {
      primes[index++] = i;
    }
  }
}

void main() {
  sieve();
  int n;
  int c = 0;
  while (scanf("%d\n", &n) != EOF && c++ < 1000) {
    printf("%d\n", n);
  }
}
