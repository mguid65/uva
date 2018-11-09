#include <cstdio>

const int coin[5] { 1, 5, 10, 25, 50 };

int main() {
  unsigned long T[7490] {0};

  T[0] = 1;
  for (int i = 0; i < 5; i++) {
    for (int j = coin[i]; j <= 7489; j++) {
      T[j] += T[j - coin[i]];
    }
  }

  int n{0};

  char c = getchar();
  while (true) {
    n = 0;
    while('0' <= c) {
      n = (n << 3) + (n << 1) + (c & 0xF);
      c = getchar();
    }

    c = getchar();
    if(c < 0) break;
    printf("%lu\n", T[n]);
  }
}

