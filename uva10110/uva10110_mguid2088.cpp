#include <cstdio>
#include <cmath>

int main() {
  long long n;
  while(scanf("%d\n", &n) == 1 && n) {
    long long root = sqrt(n);
    printf("%s\n", (root * root) == n ? "yes" : "no");
  }
}
