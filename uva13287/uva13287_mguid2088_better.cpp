#include <cstdio>

int main() {
  int x, y, total, width, count;
  char c;
  char buf[1024];
  char * pos = buf;

  while(true) {
    count = width = 0;
    while((c = getchar_unlocked()) >= '0') {
      width = (width * 10) + (c & 0xF);
    }
    if(width == 0) break;
    total = 0;
    while((c = getchar_unlocked()) >= '0') {
      count = (count * 10) + (c & 0xF);
    }
    while(count--) {
      x = y = 0;
      while((c = getchar_unlocked()) >= '0') {
        x = (x * 10) + (c & 0xF);
      }
      while((c = getchar_unlocked()) >= '0') {
        y = (y * 10) + (c & 0xF);
      }
      total += x * y;
    }
    pos += sprintf(pos, "%d\n", total/width);
  }
  fwrite_unlocked(buf, 1, pos-buf, stdout);
}
