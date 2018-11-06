#include <cstdio>

int main() {
  int cases=0, n=0, m=0;
  char c;
  while((c = getchar_unlocked()) >= '0') cases = (cases << 3) + (cases << 1) + (c & 0x0F);
  while(cases--) {
    while((c = getchar_unlocked()) >= '0') n = (n << 3) + (n << 1) + (c & 0x0F);
    while((c = getchar_unlocked()) >= '0') m = (m << 3) + (m << 1) + (c & 0x0F);
    //printf("%d %d\n", n, m);
    printf("%d\n", (m/3)*(n/3));
    n = m = 0;
  }
}
