#include <iostream>


using namespace std;

int main(){
  int W, N;
  while (scanf("%d\n%d", &W, &N) == 2) {
    int area = 0;
    int wi, li;
    while(N--) {
      cin >> wi >> li;
      area += wi*li;
    }

    cout << area/W << endl;
  }
  return 0;
}