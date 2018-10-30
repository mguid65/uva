#include <cstdio>
#include <cmath>

int main() {
  double i, j;
  while(scanf("%lf %lf", &i, &j) != EOF) {
    j = pow(j, 1/i);
    printf("%.0lf\n", j);
  }
}
