#include <cstdio>
#include <cmath>
#include <unistd.h>

int main() {
  char buf[2048];
  char * fp = buf + 2048-40;
  char * pos = buf;
  long long int i, j;
  while(scanf("%lld %lld", &i, &j) != EOF) {
    i = llabs(j-i);
    pos += sprintf(pos, "%lld\n", i);
    if (pos >= fp) {
      write(1, buf, pos - buf);
      pos = buf;
    }
  }
  if (pos > buf) write(1, buf, pos - buf);
}
