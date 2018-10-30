#include <cstdio>

int main() {
  int i, j, k, res;
  while(scanf("%d", &i)!=EOF) {
    for(int l = 0 ;l < i; l++) {
      res = 0;
      scanf("%d\n%d", &j, &k);
      for(j=j; j <= k; j+=2) {
        if(j%2==0) j += 1;
        res+=j;
      }
      printf("Case %d: %d\n", l+1, res);
    }
  }
}
