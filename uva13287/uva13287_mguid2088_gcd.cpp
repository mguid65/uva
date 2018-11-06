//0.010 seconds
//iterative is faster, avoid unecessary jumps to functions
//using dangerous, non thread safe unlocked operations
//unsafe ascii digit bound check
//since we only ever subtract from the char,
//we can unsafely assume it will never cross the upper bound

#include <cstdio>

/*
unsigned int gcd(unsigned int u, unsigned int v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }
        v = v - u;
    } while (v != 0);
    return u << shift;
}
*/
int gcd(int a, int b)
{ 
       return (b == 0 ? a : gcd(b, a % b)); 
}
int main() {
  int x, y, width, count;
  unsigned long total_w, total_l;

  char c;
  char buf[1024];
  char * pos = buf;

  while(scanf(" %d ", &width) != EOF) {
    total_w = total_l = 1;
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
      total_w *= y;
      total_l *= x;
    }
    pos += sprintf(pos , "%u\n", gcd(total_w/width, total_l));
  }
  fwrite(buf, 1, pos-buf, stdout);
}
