
/* @JUDGE_ID: 11172 C++  "Realational Operator" */

/**************
by: Carlos Mera
date: 28/10/2017

**************/
#include <cstdio>



using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int a, b;
    char res;
    scanf("%d %d", &a, &b);
    if (a == b)
      res = '=';
    else if (a < b)
      res = '<';
    else
      res = '>';

    printf("%c\n", res);
  }

  return 0;
}
