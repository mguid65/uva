#include <cstdio>
#include <unistd.h>
static int x, y, i, total, width, count;
static char input_buf[40000000];
static char buf[1024];
static char * pos = buf;
int main() {
  char c;
  i = 0;
  read(0, input_buf, 40000000);
  while(true) {
    count = width = 0;

    for(;(c =input_buf[i]) >= '0'; i++) {
      width = (width * 10) + (c & 0xF);
    } i++;
    if(!width) break;
    total = 0;

    for(;(c = input_buf[i]) >= '0'; i++) {
      count = (count * 10) + (c & 0xF);
    } i++;
    while(count--) {
      x = y = 0;

      for(;(c = input_buf[i]) >= '0';i++) {
        x = (x * 10) + (c & 0xF);
      } i++;

      for(;(c = input_buf[i]) >= '0';i++) {
        y = (y * 10) + (c & 0xF);
      } i++;

      total += x * y;
    }
    pos += sprintf(pos, "%d\n", total/width);
  }
  write(1, buf, pos-buf);
}
