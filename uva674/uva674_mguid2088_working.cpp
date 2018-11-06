#include <iostream>
#include <cstring>
#define datatype unsigned long long

int coin[5] { 1, 5, 10, 25, 50 };

int main() {
  unsigned long T[7490] {0};
  T[0] = 1;
  for (int i = 0; i < 5; i++) {
    for (int j = coin[i]; j <= 7489; j++) {
      T[j] += T[j - coin[i]];
    }
  }
  int n;
  while (scanf("%d\n", &n) != EOF) {
    printf("%lu\n", T[n]);
  }
}
