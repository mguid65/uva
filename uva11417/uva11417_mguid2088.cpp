#include <cstdio>
#include <cmath>
#include <array>
std::array<std::array<int, 502>, 502> cache {0};

unsigned gcd(int u, int v) {
  if(cache[u][v] != 0) {
    return cache[u][v];
  }
  int tmp = u;
  while ( v != 0) {
    unsigned r = u % v;
    u = v;
    v = r;
  }
  cache[tmp][v] = u;
  return u;
}

int main () {
  int input;
  while(scanf(" %d ", &input) && input != 0) {
    int g=0;
    for(int i=1;i<input;i++) {
      for(int j=i+1;j<=input;j++) {
        g+=gcd(i,j);
      }
    }
    printf( "%d\n", g);
  }
}
