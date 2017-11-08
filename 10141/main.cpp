#include <algorithm>
#include <cstdio>

struct Agency {
  char* name;
  double compliance;
  double budget;
};

using namespace std;

int main () {
  while (true) {
    int n_RFP, P;
    scanf("%d %d\n", &n_RFP, &P);
    if (n_RFP == 0 && P == 0)
      break;

    int temp = n_RFP;
    while(temp--) {
      char name_requi[80];
      scanf("%[^\n]%*c", name_requi);
    }

    Agency* agencies = new Agency[P];
    for (int i = 0; i < P; i++) {
      char agency_name[80];
      int agency_r;
      double budget;
      scanf("%[\n]%*c", agency_name);
      /*scanf("%lf %d\n", &budget, &agency_r);
      for (int i = 0; i < agency_r; i++) {
        char name_ar[80];
        scanf("%[^\n]%*c", name_ar);
      }
      agencies[i].name = name_a;
      agencies[i].budget = budget;
      agencies[i].compliance = (double) agency_r/n_RFP;*/
      //printf("%s\n", agency_name);
    }
    delete[] agencies;
  }
  return 0;
}