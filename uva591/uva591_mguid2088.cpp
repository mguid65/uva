#include <iostream>
#include <vector>
int main () {
  int i, k, count=1;
  scanf("%d ", &i);
  while(i != 0) {
    printf("Set #%d\n", count++);
    std::vector<int> bricks;
    for(int j = 0; j < i; j++) {
      scanf("%d ", &k);
      bricks.push_back(k);
    }
    int avg = 0;
    for(int l: bricks) {
      avg += l;
    }
    avg/=i;
    int diff = 0;
    for(int l: bricks) {
      if(l > avg) {
        diff += l-avg;
      }
    }
    printf("The minimum number of moves is %d.\n\n", diff);
    scanf("%d ", &i);
  }
}
