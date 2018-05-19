#include <iostream>

using namespace std;

unsigned int moreTallest(unsigned int* arr, int first, int last, unsigned int value, unsigned int res) {
  if (last >= first) {
    int mid = first + (last-first)/2;
    if ( value > arr[mid] && arr[mid] < res ) {
      return arr[mid];
    } else {
      res = value > arr[mid] ? arr[mid] : res;
      if (arr[mid] < value)
        return moreTallest(arr, mid+1, last, value, res);
      else
        return moreTallest(arr, first, mid-1, value, res);
    }
  }
  return res;
}

unsigned int moreShortest(unsigned int* arr, int first, int last, unsigned int value, unsigned int res) {
  if (last >= first) {
    int mid = first + (last-first)/2;
    if ( value < arr[mid] && arr[mid] > res ) {
      return arr[mid];
    } else {
      res = value < arr[mid] ? arr[mid] : res;
      if (arr[mid] <= value)
        return moreShortest(arr, mid+1, last, value, res);
      else
        return moreShortest(arr, first, mid-1, value, res);
    }
  }
  return res;
}

int main() {
  unsigned int N;
  cin >> N;
  unsigned int chimps[50001];

  for (int i = 0; i < N; i++) {
    cin >> chimps[i];
  }

  unsigned int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    unsigned int  Qi;
    cin >> Qi;

    unsigned int tallest_is_shorter = moreTallest(chimps, 0, N-1, Qi, 0);
    unsigned int shorter_is_tallest = moreShortest(chimps, 0, N-1, Qi, chimps[N-1]+1 );

    if ( tallest_is_shorter < 1 )
      cout << "X ";
    else
      cout << tallest_is_shorter << " ";

    if ( shorter_is_tallest == chimps[N-1]+1 )
      cout << "X" << endl;
    else
      cout << shorter_is_tallest << endl;
  }


  return 0;
}
