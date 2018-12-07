#include <cstdio>

inline void get_int(int& x) {
  x = 0;
  char c;
  while((c = getchar_unlocked()) >= '0') x = (x * 10) + (c & 0xF);
}

inline int leap(int year_1, int year_2) {
  return ((year_2 / 4) - (year_2 / 100) + (year_2 / 400)) -
         ((year_1 / 4) - (year_1 / 100) + (year_1 / 400));
}

int main() {
  int cases, day, month, year_begin, year_end;
  get_int(cases);
  for(int i = 1; i <= cases; i++) {
    get_int(day);
    get_int(month);
    get_int(year_begin);
    get_int(year_end);
    if (month != 2 || day != 29) {
      printf("Case %d: %d\n", i, year_end - year_begin);
    } else {
      printf("Case %d: %d\n", i, leap(year_begin, year_end));
    }
  }
}
