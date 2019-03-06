#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>
std::array<int, 50> cuts;

int main () {
  int initial_length, num_cuts, total_cost;
  while(scanf(" %d ", &initial_length) && initial_length != 0) {
    total_cost = initial_length;
    scanf(" %d ", &num_cuts);
    int tmp = 0;
    for(int i = 0; i < num_cuts; i++) {
      scanf(" %d ", &tmp);
      cuts[i] = tmp;
    }
    std::sort(cuts.begin(), cuts.begin()+num_cuts, [](const int& a, const int& b) {
      return a > b;
    });
    for(int i = 0; i < num_cuts; i++){
      total_cost += initial_length;
      initial_length -= cuts[i];

      if(initial_length <= 0 ) break;
    }
    printf("The minimum cutting is %d\n", total_cost);
  }

}
