#include <cstdio>
#include <set>
#include <cmath>

int main() {
  std::set<int> seen;
  int i, tmp1, tmp2;
  while(scanf("%d", &i) != EOF) {
    scanf("%d", &tmp1);
    if(i == 1) {
      printf("Jolly\n");
      continue;
    }
    for(int j=0; j<i-1; j++){
      scanf("%d", &tmp2);
      tmp1 = abs(tmp1-tmp2);
      if(tmp1 > 0 && tmp1 <= i-1) seen.insert(tmp1);
      tmp1 = tmp2;
    }
    if(seen.size() == i-1) {
      printf("Jolly\n");
    } else {
      printf("Not jolly\n");
    }
    seen.clear();
  }

}
