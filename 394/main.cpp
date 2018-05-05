#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Memory{
  int B;
  int S;
  int D;
  vector<int> U;
  vector<int> L;
};

int main () {
  int N, R;
  cin >> N >> R;
  int* C = new int[11];
  int* Index = new int [11];
  map<string, Memory> memories;

  while (N) {
    int B, S, D;
    string name;
    cin >> name;
    cin >> B >> S >> D;
    Memory temp;
    temp.B = B;
    temp.S = S;
    temp.D = D;
    temp.U.push_back(0);
    temp.L.push_back(0);
    for (int i = 1; i <= D; i++){
      int upper, lower;
      cin >> lower >> upper;
      temp.L.push_back(lower);
      temp.U.push_back(upper);
    }
    memories.insert( pair<string, Memory> (name, temp) );
    N--;
  }

  while (R) {
    string name;
    cin >> name;
    Memory& temp = memories[name];
    for (int i = 1; i <= temp.D; i++) {
      int j;
      cin >> j;
      Index[i] = j;
    }

    C[temp.D] = temp.S;
    for (int i = temp.D - 1; i >= 1; i--) {
      C[i] = C[i+1]*((temp.U)[i+1]-(temp.L)[i+1] + 1);
    }

    int acum = 0;
    for (int i = 1; i <= temp.D; i++) {
      acum += C[i]*(Index[i]-(temp.L)[i]);
    }

    int addres = temp.B + acum;

    cout << name+"[";
    for (int i = 1; i <= temp.D; i++) {
      if (i == temp.D)
        cout << Index[i] << "] = "; 
      else
        cout << Index[i] << ", "; 
    }
    cout << addres << endl;
    R--;
  }
  return 0;
}