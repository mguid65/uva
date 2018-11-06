#include <cstdio>

int main () {
  char c;
  int m, n;
  c = getchar_unlocked();
  while(true) {
    m = n = 0;
    while('0' <= c) {
      m = (m << 3) + (m << 1) + (c & 0x0F);
      c = getchar_unlocked();
    }

    c = getchar_unlocked();

    while('0' <= c) {
      n = (n << 3) + (n << 1) + (c & 0x0F);
      c = getchar_unlocked();
    }
    if(m == 0) break;
    printf("%d\n", (m * n) -1);
    c = getchar_unlocked();
  }
}
