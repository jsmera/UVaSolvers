#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;
  string trash;
  getline(cin, trash);
  int Tcase = 1;
  int memory[100];

  while(T--) {
    for (int i = 0; i < 100; i++)
      memory[i] = 0;

    int pointer = 0;
    string line;
    getline(cin, line);
    for (int i = 0; i < line.size(); i++) {
      char command = line[i];
      if (command == '>') {
        pointer = (pointer + 1) % 100;
      } else if (command == '<') {
        pointer = (100 + (pointer - 1) % 100) % 100;
      } else if (command == '+') {
        memory[pointer] = (memory[pointer] + 1)%256;
      }else if (command == '-') {
        memory[pointer] = (256 + (memory[pointer] - 1)%256)%256;
      } else if (command == '.') {
        continue;
      }
    }
    cout << "Case " << dec<<Tcase << ": ";
    for (int i = 0; i < 100; i++) {
      if (i == 99) {
        if (memory[i] <= 15)
          cout << "0" << hex<<uppercase << memory[i] << endl;
        else
          cout << hex<<uppercase << memory[i] << endl;
      } else {
        if (memory[i] <= 15)
          cout << "0" << hex<<uppercase << memory[i] << " ";
        else
          cout << hex<<uppercase << memory[i] << " ";
      }
    }
    Tcase++;
  }

  return 0;
}
