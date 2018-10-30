#include <cstdio>

int main() {
  int c;
  long long s, d, x, y;
  scanf("%d\n", &c);
  for(;c > 0; c--) {
    scanf("%lld %lld\n", &s, &d);
    x = (s + d) / 2;
    y = x - d;
    if ((s + d) % 2 == 1 || x < 0 || y < 0) {
      printf("impossible\n");
    } else {
      printf("%lld %lld\n", x, y);
    }
  }
}
