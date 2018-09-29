#include <iostream>
#include <cmath>

using namespace std;

unsigned long long Ha(unsigned long long n){
  unsigned long long res = 0;
  unsigned long long tmp = 0;
  unsigned long long i;

  unsigned long long  r = (unsigned long long)floor(sqrt(n));

  if (r*r == n) {
    res += n/r;
    r -= 1;
  }

  for(i = 1; i <= r; i=i+1 ){
    res += n/i;
    res += max(n/i-r, (unsigned long long) 0);
    // if (i > 1)
      // res += (tmp - n/i)*(i-1);
    // tmp = n/i;
  }
  // res += (tmp - n/(i))*(i-1);
  return res;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    unsigned long long n;
    cin >> n;
    if (n != 0) {
      unsigned long long ha = Ha(n);
      cout << ha <<endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}