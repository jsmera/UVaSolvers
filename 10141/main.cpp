#include <stdio.h>
#include <string>
#include <iostream>

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
      string name_requi;
      getline(cin, name_requi);
    }
    
    string win;
    int win_r = -1;
    double win_budget;
    for (int i = 0; i < P; i++) {
      string agency_name, ign;
      int agency_r;
      double budget;
      getline(cin, agency_name);
      scanf("%lf %d\n", &budget, &agency_r);

      if (agency_r > win_r) {
        win = agency_name;
        win_budget = budget;
        win_r = agency_r;
      } else if(agency_r == win_r) {
        if (budget < win_budget) {
          win = agency_name;
          win_budget = budget;
          win_r = agency_r;
        }
      }

      for (int i = 0; i < agency_r; i++) {
        getline(cin, ign);
      }
    }
    if (n_case > 1)
      printf("\nRFP #%d\n%s\n", n_case, win.c_str());
    else
      printf("RFP #%d\n%s\n", n_case, win.c_str());
  }
  return 0;
}