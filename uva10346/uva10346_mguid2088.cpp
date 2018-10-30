#include <cstdio>

int main() {
  long n, i;
  while(scanf("%ld %ld", &n, &i) != EOF) {
    printf("%ld\n", n+(n-1)/(i-1));
  }
}
