#include <cstdio>

int main () {
  long current;
  int in, out;
  while(scanf(" %d ", &in) != EOF) {
    current = out = 1;
    while(current % in != 0) {
      current = (current * 10 + 1) % in;
      out++;
    }
    printf("%d\n", out);
  }
}
