#include <iostream>
#include <queue>

using namespace std;

struct Car {
  int pos;
  int time;
  Car (int a, int b) {
    pos = a;
    time = b;
  }
};

int main() {
  int C;
  cin >> C;
  queue<Car> left;
  queue<Car> right;

  while(C--) {
    int n, t, m;
    cin >> n >> t >> m;

    for (int i = 0; i < m; i++) {
      int time_arrival;
      string bank;
      cin >> time_arrival >> bank;
      Car temp(i, time_arrival);

      if (bank == "left")
        left.push(temp);
      else
        right.push(temp);
    }

    int time = 0, cars_loaded = 0;
    queue<Car>* bank_now = &left;
    
    int res[10001];

    while ( !left.empty() || !right.empty() ) {
      cars_loaded = 0;

      int wait = left.empty() ? right.front().time :
      right.empty()? left.front().time :
      min(left.front().time, right.front().time);
      
      time = max(time, wait);
      
      while (!bank_now->empty() && cars_loaded < n && bank_now->front().time <= time) {
        res[bank_now->front().pos] = time + t;
        cars_loaded++;
        bank_now->pop();
      }

      time = time + t;

      if (bank_now == &left)
        bank_now = &right;
      else
        bank_now = &left;
    }

    for (int j = 0; j < m; j++) cout << res[j] << endl;
    
    if (C) cout << endl;
  }

  return 0;
}
