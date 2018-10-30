#include <stdio.h>

#define MAX_SIZE (3837360)

static int days_in_months[] = {0, 31, 28, 31,  30,  31,  30,  31,  31,  30,  31,  30,  31, 0};
static int days_in_leap_months[] = {0, 31, 29, 31,  30,  31,  30,  31,  31,  30,  31,  30,  31, 0};

static int normalize_days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365, 0};
static int normalize_leap_days[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366, 0};


int days_in_year[MAX_SIZE];

int is_leap_year(int year) {
  return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int main() {
  int count = 0;
  int i;
  for(i = 1; i < MAX_SIZE;) {
    days_in_year[i++] = count;
    count += 365;
    days_in_year[i++] = count;
    count += 365;
    days_in_year[i++] = count;
    count += 365;
    if((i % 100 != 0) || (i % 400 == 0)) {
      days_in_year[i++] += count;
      count += 366;
    } else {
      days_in_year[i++] += count;
      count += 365;
    }
  }
  int day_offset, day, month, year, total_days;
  while(scanf("%d %d %d %d\n", &day_offset, &day, &month, &year) == 4 && year) {
    total_days = days_in_year[year];
    total_days += is_leap_year(year) ? normalize_leap_days[month-1] : normalize_days[month-1];
    total_days += day;
    total_days += day_offset;

    int tmp = 1 + day_offset / 365 + year;

    while(days_in_year[tmp] >= total_days) {
      tmp--;
    }
    year = tmp;
    total_days -= days_in_year[year];
    tmp = 0;

    if(is_leap_year(year)) {
      while(normalize_leap_days[tmp] < total_days) {
        tmp++;
      }
      month = tmp;
      total_days -= normalize_leap_days[month-1];
    } else {
      while(normalize_days[tmp] < total_days) {
        tmp++;
      }
      month = tmp;
      total_days -= normalize_days[month-1];
    }

    printf("%d %d %d\n", total_days, month, year);
  }
}
