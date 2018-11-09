#include <cstdio>
#include <cmath>

int main() {
  int a, b, d, i, count;
  char c;
  while(true) {
    a = b = count = 0;
    while((c = getchar_unlocked()) >= '0') {
      a = (a * 10) + (c & 0xF);
    }
    while((c = getchar_unlocked()) >= '0') {
      b = (b * 10) + (c & 0xF);
    }
    if(a + b == 0) break;
    //printf("%d %d\n", a, b);
    for(i = a; i <= b; i++) {
      d = sqrt(i);
      if(d * d == i) {
        count++;
      }
    }
    printf("%d\n", count);
  }
}
