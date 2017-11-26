#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

unsigned int Teams[1000000];

int main() {
  int T, nCase = 0;
  while(scanf("%d", &T), (T)) {
    list<int> Queue[1000];
    int slots[1000];
    nCase++;
    for (int i = 0; i < T; i++) {
      unsigned int team;
      scanf("%d", &team);
      for (int j = 0; j < team; j++) {
        int E;
        scanf("%d", &E);
        Teams[E] = i;
      }
      slots[i] = -1;
    }

    printf("Scenario #%d\n", nCase);
    int number, posDequeue = 0, posEnqueue = 0;
    char operation[100];

    while(scanf("%s", &operation)) {
      if ( operation[0] == 'S' ) break;
      scanf("%d", &number);
      if ( operation[0] == 'E') {
        if (slots[Teams[number]] < 0) {
          Queue[posEnqueue].push_back(number);
          slots[Teams[number]] = posEnqueue;
          posEnqueue++;
        } else {
          if ( Queue[slots[Teams[number]]].empty() ) {
            Queue[posEnqueue].push_back(number);
            slots[Teams[number]] = posEnqueue;
            posEnqueue++;
          }
          else Queue[slots[Teams[number]]].push_back(number);
        }
      }
      else {
        printf("%d\n", Queue[posDequeue].front());
        Queue[posDequeue].pop_front();
        if ( Queue[posDequeue].empty() ) posDequeue++;
      }
    }
    printf("\n");
  }
  return 0;
}