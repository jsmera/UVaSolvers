#include <iostream>

using namespace std;

int main() {
  int n;
  unsigned long long A[4], B[4];
  A[0] = 0, A[1] = 0, A[2] = 0, A[3] = 0;
  B[0] = 0, B[1] = 0, B[2] = 0, B[3] = 0;

  unsigned long long int colours[3];
  colours[0] = 0, colours[1] = 0, colours[2] = 0;

  while(scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++) {
      unsigned long long temp;
      cin >> temp;
      A[i%3] += temp;
    }
    for (int i = 1; i <= n; i++) {
      unsigned long long temp;
      cin >> temp;
      B[i%3] += temp;
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        colours[(i+j)%3] += A[i]*B[j];
      }
    }

    cout << colours[0] << " " << colours[1] << " " << colours[2] << endl;
    colours[0] = 0, colours[1] = 0, colours[2] = 0;
    A[0] = 0, A[1] = 0, A[2] = 0;
    B[0] = 0, B[1] = 0, B[2] = 0;
  }
  return 0;
}