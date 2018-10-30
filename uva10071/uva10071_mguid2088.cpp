#include <cstdio>

int main () {
  int i, j;
  while(scanf("%d %d\n", &i, &j) != EOF) {
    i = (i*j) *2;
    printf("%i\n", i);
  }
  return 0;
}
