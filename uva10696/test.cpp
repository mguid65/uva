#include <cstdio>
#include <unistd.h>

int main(){
  char buf[4096];
  char * pos = buf;
  char * flush_point = buf +4096 -40;
  unsigned n;
  while(scanf("%u\n", &n) && n) {
      pos += sprintf(pos ,"f91(%u) = %u\n", n, (n > 100) ? n-10 : 91);
      if (pos >= flush_point) {
          write(1, buf, pos - buf);
          pos = buf;
      }

  }
  if (pos > buf) {
      write(1, buf, pos - buf);
  }
}
