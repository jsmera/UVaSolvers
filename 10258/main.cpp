#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

struct User{
  int id;
  int problems_solved;
  int time_penality;

  User() {
    id = 0;
    problems_solved = 0;
    time_penality = 0;
  }
};

bool comp(User& a, User& b) {
  if (a.id == 0)
    return false;
  if (b.id == 0)
    return true;
  if (a.problems_solved == b.problems_solved && a.time_penality == b.time_penality)
    return a.id < b.id;
  if (a.problems_solved > b.problems_solved)
    return true;
  if (a.time_penality < b.time_penality)
    return true;
  return false;
}

int main() {
  int T;
  User users[103];
  cin >> T;
  stringstream ss;
  string line;
  getline(cin, line), getline(cin, line);
  while(T--) {
    int ID, P, time;
    char L;
    int last = 0;
    while (getline(cin, line)) {
      if ( line.empty() ) break;
      ss.clear();
      ss << line;
      ss >> ID >> P >> time >> L;

      if ( !users[ID].id ) users[ID].id = ID;
      if (L == 'C') {
        users[ID].time_penality += time;
        // users[ID].problems_solved += 1;
      }
      else if(L == 'I') {
        users[ID].time_penality += 20;
      }

      last = last < ID ? ID : last;
    }

    sort(users+1, users+last+1, comp);
    
    for (int i = 1; i <= last; i++) {
      if ( users[i].id ) {
        cout << users[i].id << " " << users[i].problems_solved << " " << users[i].time_penality << endl;
        users[i].id = 0;
        users[i].problems_solved = 0;
        users[i].time_penality = 0;
      }
    }
    if (T) cout << endl;
  }

  return 0;
}