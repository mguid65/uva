#include <cstdio>
#include <cmath>
#include <algorithm>

char c;

inline void get_int(int& res) {
  int i = 1;
  while((c = getchar_unlocked()) >= '-') {
    if (c == '-') i = -1;
    else res = (res * 10) + (c & 0xF);
  }
  res *= i;
}

int main() {
  int num = 0;
  get_int(num);
  int cases = 1;
  while(num >= 0) {
    printf("Case %d: %.0f\n", cases, std::max(0.0, ceil(log(num) / log(2))));
    cases++;
    num = 0;
    get_int(num);
  }
}
