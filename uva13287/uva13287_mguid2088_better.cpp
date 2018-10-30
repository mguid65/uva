//0.010 seconds
//iterative is faster, avoid unecessary jumps to functions
//using dangerous, non thread safe unlocked operations
//unsafe ascii digit bound check
//since we only ever subtract from the char,
//we can unsafely assume it will never cross the upper bound

#include <cstdio>

int main() {
  int x, y, total, width, count, input;

  char c;
  char buf[1024];
  char * pos = buf;

  while(scanf(" %d ", &width) != EOF) {
    total = 0;
    count = getchar_unlocked() - '0';
    c = getchar_unlocked(); //danger, assuming the next character is correctly formatted

    while('0' <= c) { //unsafe ignore upper bound
      count = (count * 10) + c - '0';
      c = getchar_unlocked();
    }
    while(count--) {
      x = y = 0;
      x = getchar_unlocked() - '0';
      c = getchar_unlocked(); //danger, assuming the next character is correct formatted
      while('0' <= c) {
        x = (x * 10) + c - '0';
        c = getchar_unlocked();
      }
      y = getchar_unlocked() - '0';
      c = getchar_unlocked(); //danger, assuming the next character is correct formatted
      while('0' <= c) { //unsafe ignore upper bound
        y = (y * 10) + c - '0';
        c = getchar_unlocked();
      }
      total += x * y;
    }
    pos += sprintf(pos , "%d\n", total/width);
  }
  fwrite(buf, 1, pos-buf, stdout);
}
