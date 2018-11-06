//0.010 seconds
//iterative is faster, avoid unecessary jumps to functions
//using dangerous, non thread safe unlocked operations
//unsafe ascii digit bound check
//since we only ever subtract from the char,
//we can unsafely assume it will never cross the upper bound

#include <cstdio>

int main() {
  int x, y, total, width = 0, count, input;
  bool end = false;
  char c;
  char buf[1024];
  char * pos = buf;

  while('0' <= c) { //unsafe ignore upper bound
    //printf("%c\n", c);
    width = (width * 10) + c - '0';
    c = getchar_unlocked();
  }
  c = getchar_unlocked();
  while(!end) {
    //printf("%d\n", width);
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
    c = getchar_unlocked();
    if(c == EOF) {
      end = true;
      break;
    }
    width = 0;
    while('0' <= c) { //unsafe ignore upper bound
      if(c == EOF) {
        end = true;
        break;
      }
      width = (width * 10) + c - '0';
      c = getchar_unlocked();
    }
  }
  fwrite_unlocked(buf, 1, pos-buf, stdout);
}
