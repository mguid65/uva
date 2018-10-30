#include <cstdio>


int main () {
  int cases, walls, last_height, curr_height, low=0, high=0;

  scanf ("%d", &cases );
  for (int i = 1; i <= cases; i++ ) {

    scanf ( "%d", &walls);
    low = high = curr_height = last_height = curr_height= 0;
    scanf("%d", &last_height);
    for (int j = 1; j < walls; j++ ) {
      scanf ( "%d", &curr_height );
      if ( curr_height > last_height ) high++;
      if ( curr_height < last_height ) low++;
      last_height = curr_height;
    }
    printf("Case %d: %d %d\n", i, high, low);
  }
}


