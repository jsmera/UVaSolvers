#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool closesParentheses(char a, char b) {
  if (a == '(' && b == ')') return true;
  if (a == '[' && b == ']') return true;
  else return false;
}

bool opens(char a) {
  return (a == '(' || a == '[');
}

int main() {
  int n;
  scanf("%d\n", &n);
  while (n--) {
    string parentheses;
    stack<char> remid;
    getline(cin, parentheses);
    bool condition = true;
    for (int i = 0; i < parentheses.length(); i++) {
      if (opens(parentheses[i])) {
        remid.push(parentheses[i]);
      }
      else {
        if (remid.empty()) {
          condition = false;
          break;
        }
        else if ( closesParentheses(remid.top(), parentheses[i]) ) {
          remid.pop();
        } else {
          condition = false;
          break;
        }
      }
    }
    if (condition && remid.empty()) printf("Yes\n"); 
    else printf("No\n");
  }
  return 0;
}