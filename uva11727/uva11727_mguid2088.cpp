#include <algorithm>
#include <array>
#include <cstdio>

int main () {
  std::array<int, 3>workers;
  int j;
  scanf("%d", &j);
  for(int i = 1; i <= j; i++) {
    scanf("%d %d %d", &workers[0], &workers[1], &workers[2]);
    std::sort(workers.begin(), workers.end());
    printf("Case %d: %d\n", i, workers[1]);
  }
}
