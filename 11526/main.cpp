#include <iostream>
#include <cmath>

using namespace std;
double H[4294967296];
unsigned int last;

void armonic(unsigned int* n) {
  if (last < *n) {
    for (unsigned int i = last; i <= *n; i++) {
      H[i] = H[i-1] + 1/(double)i;
    }
    last = *n;
  }
};

long long Ha(int n){
  long long res = 0;
  for( int i = 1; i <= sqrt(n); i=i+1 ){
    res = (res + n/i);
  }
  return res;
}

long long Hai(int n){
  long long res = 0;
  for( int i = 1; i <= n; i=i+1 ){
    res = (res + n/i);
  }
  return res;
}

int main() {
  H[0] = 0;
  last = 1;
  int T;
  cin >> T;
  while (T--) {
    unsigned int n;
    cin >> n;
    long long ha = Ha(n), hai = Hai(n);
    // armonic(&n);
    cout << "n: "<< n << " " << hai 
    << " " << ha << " " << hai-ha << endl;
    cout << endl;
  }

  return 0;
}