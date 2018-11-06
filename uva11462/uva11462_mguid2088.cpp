#include <cstdio>
#include <algorithm>

int main () {
  int ages[2000000];

  int n, age;

  while(scanf("%d", &n) && n != 0) {
    for(int i = 0; i < n; i++) {
      scanf("%d", &ages[i]);
    }
    std::sort(ages, ages + n);
    for(int i = 0; i < n; i++) {
      printf("%d", ages[i]);
      if(i+1 < n) printf(" ");
    }
    printf("\n");
  }
}
