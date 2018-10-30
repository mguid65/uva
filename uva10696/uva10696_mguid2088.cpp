#include <cstdio>

int main(){
  unsigned n;
  while(scanf("%u\n", &n) && n) {
      printf("f91(%d) = %d\n", n, (n <= 100) ? 91 :n - 10);
  }
}
