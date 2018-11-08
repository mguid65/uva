//0.010 seconds
//iterative is faster, avoid unecessary jumps to functions
//using dangerous, non thread safe unlocked operations
//unsafe ascii digit bound check
//since we only ever subtract from the char,
//we can unsafely assume it will never cross the upper bound

#include <cstdio>

int main() {
  int x, y, i, total, width=0, count=0, input;
  char c;
  char buf[1024];
  char * pos = buf;

  char line[16];
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
      fgets_unlocked(line, 16, stdin);
      x = y = i = 0;
      for(;;i++) {
        if(line[i] == ' ') break;
        x = (x * 10) + (line[i] & 0xF);
      }
      i++;
      for(;;i++) {
        if(line[i] < '0') break;
        y = (y * 10) + (line[i] & 0xF);
      }
      total += x * y;
    }
    pos += sprintf(pos , "%d\n", total/width);
  }
  fwrite_unlocked(buf, 1, pos-buf, stdout);
}
