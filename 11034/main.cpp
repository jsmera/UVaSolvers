#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<double> banks[2];

  int C;
  cin >> C;
  while(C--) {
    int l, m;
    cin >> l >> m;

    for (int i = 0; i < m; i++) {
      int car_long;
      string bank;
      cin >> car_long >> bank;
      if (bank[0] == 'l')
        banks[0].push((double)car_long/100);
      else
        banks[1].push((double)car_long/100);
    }

    int side = 0, travels = 0;
    double capacity;
    while (!banks[0].empty() || !banks[1].empty()) {
      capacity = (double)l;
      while ( !banks[side].empty() && capacity >= banks[side].front() ) {
        capacity = capacity - banks[side].front();
        banks[side].pop();
      }
      travels++;
      side = (side + 1)%2;
    }
    cout << travels << endl;
  }
  return 0;
}