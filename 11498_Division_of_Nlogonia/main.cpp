/* @JUDGE_ID: 11498 C++  "Division of Nlogonia" */

/**************
by: Carlos Mera
date: 6/11/2017

**************/
#include <iostream>

using namespace std;

int main() {
  int K;
  cin >> K;
  while(K !=0 ) {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < K; i++) {
      int N1, M1;
      cin >> N1 >> M1;

      if (N1 > N && M1 > M)
        cout << "NE" << endl;
      else if (N1 < N && M1 > M)
        cout << "NO" << endl;
      else if (N1 < N && M1 < M)
        cout << "SO" << endl;
      else if (N1 > N && M1 < M) 
        cout << "SE" << endl;
      else if (N1 == N || M1 == M)
        cout << "divisa" << endl;
    }

    cin >> K;
  } 
  return 0;
}