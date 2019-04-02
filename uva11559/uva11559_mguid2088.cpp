#include <cstdio>

int main() {

  int num_attending, budget, num_hotels,
      week, min_cost, price_per_person,
      beds_per_weekend, tmp_cost;

  while ( scanf(" %d %d %d %d ",
          &num_attending, &budget, &num_hotels, &week) != EOF ) {
    min_cost = 500001;

    for ( int i = 0; i < num_hotels; ++i ) {
      scanf(" %d ", &price_per_person);
      for ( int j = 0; j < week; ++j ) {
        scanf(" %d ", &beds_per_weekend);
        tmp_cost = price_per_person * num_attending;
        min_cost = ( beds_per_weekend >= num_attending && tmp_cost <= min_cost ) ? tmp_cost : min_cost;
      }
    }
    if ( min_cost <= budget ) printf("%d\n", min_cost);
    else puts("stay home");
  }
}
