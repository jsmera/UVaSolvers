#include <cstdio>

using namespace std;

int main () {
  int n_case = 0;
  while (true) {
    n_case++;
    int n_RFP, P;
    scanf("%d %d\n", &n_RFP, &P);
    if (n_RFP == 0 && P == 0)
      break;

    int temp = n_RFP;
    while(temp--) {
      char name_requi[80];
      scanf("%[^\n]%*c", name_requi);
    }
    
    char* win;
    double win_r = -1, win_budget;
    for (int i = 0; i < P; i++) {
      char agency_name[80], ign[80];
      int agency_r;
      double budget;
      gets(agency_name);
      scanf("%lf %d\n", &budget, &agency_r);
      
      if (win_r < agency_r && agency_r <= n_RFP) {
        printf("%s %d %d\n", agency_name, agency_r, n_RFP);
        win = agency_name;
        win_budget = budget;
        win_r = agency_r;
      }

      for (int i = 0; i < agency_r; i++) {
        gets(ign);
      }
    }
    printf("RFP #%d: %s\n", n_case, win);
  }
  return 0;
}