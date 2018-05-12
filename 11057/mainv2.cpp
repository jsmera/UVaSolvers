#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  unsigned int prices[9999];
  unsigned int N;
  cin >> N;
  while ( !cin.eof() ) {
    unsigned int M;
    
    for (int i = 0; i < N; i++) {
      cin >> prices[i];
    }
    
    sort(prices, prices+N);
    cin >> M;

    unsigned int maxDiff = 1000001;
    unsigned int I, J;
    for (int i = 0; i < N; i++) {
      int diff = M - prices[i];
      if (binary_search(prices+i+1, prices+N, diff)) {
        if (maxDiff < prices[i]-diff) {
          maxDiff = prices[i]-diff;
          I = prices[i];
          J = diff;
        }
      }
    }

    cout << "Peter should buy books whose prices are " <<  I << " and " << J << "." << endl;
    cout << endl;
    cin >> N;
  }
  return 0;
}
