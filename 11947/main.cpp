#include <cstdio>

bool isLeapYears (int& n) {
  return !(n%4) && ((n%100) || !(n%400));
}

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int N, n_case = 1;
  scanf("%d\n", &N);

  while(N--) {
    int day, month, year, days_after;
    scanf("%2d%2d%4d\n", &month, &day, &year);
    
    if (isLeapYears(year)) {
      days[2] = 29;
    }
    days_after = 40*7;
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

    if ((res_month == 1 && res_day >= 21) || (res_month == 2 && res_day <= 19))
      printf("%d %02d/%02d/%d aquarius\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 2 && res_day >= 20) || (res_month == 3 && res_day <= 20))
      printf("%d %02d/%02d/%d pisces\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 3 && res_day >= 21) || (res_month == 4 && res_day <= 20))
      printf("%d %02d/%02d/%d aries\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 4 && res_day >= 21) || (res_month == 5 && res_day <= 21))
      printf("%d %02d/%02d/%d taurus\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 5 && res_day >= 22) || (res_month == 6 && res_day <= 21))
      printf("%d %02d/%02d/%d gemini\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 6 && res_day >= 22) || (res_month == 7 && res_day <= 22))
      printf("%d %02d/%02d/%d cancer\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 7 && res_day >= 23) || (res_month == 8 && res_day <= 21))
      printf("%d %02d/%02d/%d leo\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 8 && res_day >= 22) || (res_month == 9 && res_day <= 23))
      printf("%d %02d/%02d/%d virgo\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 9 && res_day >= 24) || (res_month == 10 && res_day <= 23))
      printf("%d %02d/%02d/%d libra\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 10 && res_day >= 24) || (res_month == 11 && res_day <= 22))
      printf("%d %02d/%02d/%d scorpio\n", n_case, res_month, res_day, res_year);
    else if ((res_month == 11 && res_day >= 23) || (res_month == 12 && res_day <= 22))
      printf("%d %02d/%02d/%d sagittarius\n", n_case, res_month, res_day, res_year);
    else
      printf("%d %02d/%02d/%d capricorn\n", n_case, res_month, res_day, res_year);
    n_case++;
  }

  return 0;
}