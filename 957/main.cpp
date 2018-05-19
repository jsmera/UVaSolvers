#include <iostream>

using namespace std;

int lowerBound(int* arr, int first, int last, int value, int res) {
  if (last >= first) {
    int mid = first + (last-first)/2;
    if ( value >= arr[mid] && arr[mid] < arr[res] ) {
      return mid;
    } else {
      res = value >= arr[mid] ? mid : res;
      if (arr[mid] <= value)
        return lowerBound(arr, mid+1, last, value, res);
      else
        return lowerBound(arr, first, mid-1, value, res);
    }
  }
  return res;
}

int main() {
  int Y;
  while (cin >> Y) {
    int P;
    cin >> P;
    int popes[100001];
    popes[0] = 0;

    for (int i = 0; i < P; i++) {
      cin >> popes[i+1];
    }

    int max_popes = 0, max, min;
    int i = 1;
    while (i <= P && popes[i]+Y-1 <= popes[P]) {
      int limit_upper = lowerBound(popes, 1, P-1, popes[i]+Y-1, 0);
      int n_popes = 0;

      for (int j = i; j <= limit_upper; j++) {
        n_popes++;
      }

      if (n_popes > max_popes) {
        max_popes = n_popes;
        min = i;
        max = limit_upper;
      }

      i++;
    }

    cout << max_popes << " " << popes[min] << " "<< popes[max] << endl; 
  }

  return 0;
}
