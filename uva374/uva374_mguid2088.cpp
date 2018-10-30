#include <cstdio>

int main () {
  unsigned long long b, p, m, res;
  while(scanf("%llu %llu %llu\n\n", &b, &p, &m) != EOF) {
    res=1;
    b%=m;

    while(p) {
        if(p&1)
        res = (res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    printf("%llu\n", res);
  }

}
