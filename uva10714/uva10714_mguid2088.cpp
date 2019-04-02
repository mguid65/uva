#include <algorithm>
#include <cstdio>

using std::max;
using std::min;

int main () {
  int cases, dist;
  scanf("%d", &cases);

  while (cases--) {
    int l, n, min_dist = 0, max_dist = 0;
    scanf("%d %d", &l, &n);

    while (n--) {
      scanf("%d", &dist);

      dist = dist < ( l - dist ) ? dist : l - dist;
      if (min_dist < dist) min_dist = dist;
      if (max_dist < (l - dist)) max_dist = l - dist;
    }
    printf("%d %d\n", min_dist, max_dist);
  }
}
