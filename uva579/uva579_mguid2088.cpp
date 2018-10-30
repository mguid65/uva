#include <cstdio>
#include <cmath>

int main () {
  double h, m;
  while(scanf("%lf:%lf\n", &h, &m)) {
    if(h == 0 && m == 0) break;
    h = ((h*30) + (m/2))-(m*6);
    if(h < 0) h*=-1;
    printf("%.3lf\n", h > 180 ? 360.0 - h : h );
  }
}
