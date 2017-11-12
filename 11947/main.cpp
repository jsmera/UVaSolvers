#include <cstdio>

bool isLeapYears (int& n) {
  return !(n%4) && ((n%100) || !(n%400));
}

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int N;
  scanf("%d\n", &N);

  while(N--) {
    int day, month, year;
    scanf("%2d%2d%4d\n", &month, &day, &year);
    day+=280;
    while (day > days[month]) {
      day-=month;
      month++;
      if (month==12) {
        month=1;
        year++;
        days[2] = isLeapYears(year) ?  29: 28;
      }
    }

    printf("%d %d %d\n", day, month, year);
  }
  return 0;
}