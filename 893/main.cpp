#include <cstdio>

bool isLeapYears (int& n) {
  return !(n%4) && ((n%100) || !(n%400));
}

int main() {
  int days_after, day, month, year;

  while (scanf("%d %d %d %d\n", &days_after, &day, &month, &year), (days_after || day || month || year)) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYears(year)) {
      days[2] = 29;
    }

    int res_day = day, res_month = month, res_year = year;
    while(days_after > 0) {
      if (res_day+days_after <= days[res_month]) {
        res_day+=days_after;
        days_after = 0;
      } else {
        if (res_day == days[res_month]) {
          res_day = 1;
          if (res_month == 12) {
            res_month = 1;
            res_year++;
            days[2] = isLeapYears(res_year) ? 29: 28;
          } else {
            res_month++;
          }
          days_after--;
        } else {
          days_after -= days[res_month]-res_day;
          res_day += days[res_month]-res_day;
        }
      }
    }

    printf("%d %d %d\n", res_day, res_month, res_year);
  }
  return 0;
}