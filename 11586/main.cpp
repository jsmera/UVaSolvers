#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;
  string trash;
  getline(cin, trash);
  while (T) {
    int p1 = 0, p2 = 0;
    string line;
    getline(cin, line);
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == 'F')
        p1++;
      else if (line[i] == 'M' )
        p2++;
    }

    if ( p1 == p2 && p1 > 1 && p2 > 1)
      cout << "LOOP" << endl;
    else
      cout << "NO LOOP" << endl;

    T--;
  }

  return 0;
}