#include <iostream>
#include <vector>

using namespace std;

int main() {
  unsigned int prices[9999];
  unsigned int N;
  cin >> N;
  while ( !cin.eof() ) {
    unsigned int M, n_prices;
    n_prices = 0;
    
    vector<int> winners;
    for (int i = 0; i < N; i++) {
      cin >> prices[i];
      n_prices++;
    }
    
    cin >> M;

    for (int i = 0; i < n_prices; i++) {
      int diff = M - prices[i];
      for (int j = i+1; j < n_prices; j++) {
        if ( diff == prices[j] ) {
          if (prices[i] >= prices[j]) {
            winners.push_back(prices[j]);
            winners.push_back(prices[i]);
          } else {
            winners.push_back(prices[i]);
            winners.push_back(prices[j]);
          }
          break;
        }
      }
    }
    int i = winners[0], j = winners[1];
    for (int k = 2; k < winners.size(); k+=2) {
      if ( winners[k+1]-winners[k] < j-i && winners[k] <= winners[k+1]) {
        i = winners[k];
        j = winners[k+1];
      }
    }
    cout << "Peter should buy books whose prices are " <<  i << " and " << j << "." << endl;
    cout << endl;
    cin >> N;
  }
  return 0;
}
