#include <cstdio>
#include <algorithm>

int main () {
  int i, j, k, train[50], count = 0;
  scanf("%d", &i);
  for(int l = 0;l < i; l++) {
    scanf("%d", &j);
    for(int k = 0;k < j; k++) {
      scanf("%d", &train[k]);
    }
    count = 0;
    bool swapped = true;
    while(swapped) {
      swapped = false;
      for( int m = 0; m < j-1; m++) {
        if (train[m] > train[m+1]) {
          std::swap(train[m], train[m+1]);
          count++;
          swapped = true;
        }
      }
    }
    printf("Optimal train swapping takes %d swaps.\n", count);
  }
}
