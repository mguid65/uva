#include <cstdio>
#include <cstring>
#include <algorithm>

int N, m[105][105], x[105];

int main() {
  while(scanf("%d ", &N) != EOF) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d ", &m[i][j]);
      }
    }
    int max_sum = -200;
    for (int i = 0; i < N; i++) {
      memset(x, 0, sizeof(x));
      for (int j = i; j < N; j++) {
        for (int k = 0; k < N; k++) x[k] += m[j][k];
        int cur_sum=x[0], sum=0;
        for (int l = 0; l < N; l++) {
          sum += x[l];
          cur_sum = std::max(sum, cur_sum);
          if (sum < 0) sum = 0;
        }
        max_sum = std::max(max_sum, cur_sum);
      }
    }
    printf("%d\n", max_sum);
  }
}
