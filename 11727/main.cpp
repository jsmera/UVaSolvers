/* @JUDGE_ID: 11727 C++  "Cost Cutting" */

/**************
by: Carlos Mera
date: 6/11/2017

**************/
#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    unsigned int emp1, emp2, emp3;
    cin >> emp1 >> emp2 >> emp3;

    if ( (emp1 >= emp2 && emp2 >= emp3) || (emp3 >= emp2 && emp2 >= emp1) ) {
      cout << "Case "<< i+1 << ": " << emp2 << endl;
      continue;
    }

    if ( (emp2 >= emp1 && emp1 >= emp3) || (emp3 >= emp1 && emp1 >= emp2) ) {
      cout << "Case "<< i+1 << ": " << emp1 << endl;
      continue;
    }

    if ( (emp1 >= emp3 && emp3 >= emp2) || (emp2 >= emp3 && emp3 >= emp1) ) {
      cout << "Case "<< i+1 << ": " << emp3 << endl;
      continue;
    }
  }

  return 0;
}