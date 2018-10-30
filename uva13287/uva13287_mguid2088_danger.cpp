//0.010 seconds
//iterative is faster, avoid unecessary jumps to functions
//using dangerous, non thread safe unlocked operations

#include <cstdio>
#include <cctype>
#include <unistd.h>

int main() {
  int x, y, total, width, count, input;
  input = 0 < (scanf(" %d ", &width));

  char c;
  char buf[1024];
  char * pos = buf;

  while(input) {
    total = 0;
    count = getchar_unlocked() - '0';
    c = getchar_unlocked(); //danger, assuming the next character is correctly formatted

    while(('0' <= c) && ('9' >= c)) {
      count = (count << 3) + (count << 1) + c - '0';
      c = getchar_unlocked();
    }
    while(count--) {
      x = y = 0;
      x = getchar_unlocked() - '0';
      c = getchar_unlocked(); //danger, assuming the next character is correct formatted
      while(('0' <= c) && ('9' >= c)) {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar_unlocked();
      }
      y = getchar_unlocked() - '0';
      c = getchar_unlocked(); //danger, assuming the next character is correct formatted
      while(('0' <= c) && ('9' >= c)) {
        y = (y << 3) + (y << 1) + c - '0';
        c = getchar_unlocked();
      }
      total += x * y;
    }
    pos += sprintf(pos , "%d\n", total/width);
    input = 0 < (scanf(" %d ", &width));
  }
  fwrite(buf, sizeof(char), pos-buf, stdout);
  //_exit(0);
}
