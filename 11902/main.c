#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"


int graph[100][100];

void dfs(int root, bool* visited, int no_target, int n) {
  visited[root] = true;
  int i;
  for (i = 0; i < n; i++) {
    if ( graph[root][i] == 1 && !visited[i] && i != no_target ) {
      visited[i] = true;
      dfs(i, visited, no_target, n);
    }
  }
}

int main() {
  int T, c = 1;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    int pivot, i, j;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (j == n ) {
          scanf("%d ", &pivot);
        } else {
          scanf("%d", &pivot);
        }
        graph[i][j] = pivot;
      }
    }
    char * banner = malloc(2*n+2 * sizeof(char));
    banner[0] = '+';
    banner[2*n] = '+';
    banner[2*n+1] = '\0';
    for (i = 1; i < 2*n; i++){
      banner[i] = '-';
    }
    bool * reachable = calloc(n, sizeof *reachable);
    dfs(0, reachable, -1, n);
    bool * v;
    printf("Case %d:\n%s\n", c++, banner);
    for (i = 0; i < n; i++) {
      if (i == n-1) {
        printf("|%c|\n", reachable[i] ? 'Y': 'N');
      } else {
        printf("|%c", reachable[i] ? 'Y': 'N');
      }
    }
    printf("%s\n", banner);
    for (i = 1; i < n; i++) {
      if (reachable[i]) {
        v = calloc(n, sizeof *reachable);
        dfs(0, v, i, n);
        for (j = 0; j < n; j++) {
          if (j == n-1) {
            printf("|%c|", !v[j] && reachable[j] ? 'Y': 'N');
          } else {
            printf("|%c", !v[j] && reachable[j] ? 'Y': 'N');
          }
        }
        printf("\n%s\n", banner);
        free(v);
      } else {
        for (j = 0; j < n; j++) {
          if (j == n-1) {
            printf("|N|");
          } else {
            printf("|N");
          }
        }
        printf("\n%s\n", banner);
      }
    }
    free(reachable);
    free(banner);
  }
  return 0;
}
