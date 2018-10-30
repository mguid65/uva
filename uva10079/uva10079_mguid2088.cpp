#include <cstdio>

int main() {
  int n;
  while(scanf("%d\n", &n) == 1 && n >= 0) {
    printf("%lu\n", ((unsigned long)n*((unsigned long)(n+1))/2) + 1);
  }
}
