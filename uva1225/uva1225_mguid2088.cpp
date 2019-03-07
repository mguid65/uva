#include <unordered_map>
#include <vector>
#include <numeric>

int main () {
  int counts, n;
  scanf(" %d ", &counts);
  while(counts--) {
    std::unordered_map<int, int> int_map;
    scanf(" %d ", &n);
    std::vector<int> nums(n);
    std::iota(nums.begin(), nums.end(), 1);
    for (auto & i: nums) {
      while(i > 0) {
        int_map[i % 10]++;
        i /= 10;
      }
    }
    for( int i = 0; i < 10; i++) {
      if(i == 0) printf("%d", (int_map[i]));
      else printf(" %d", (int_map[i]));
    }
    puts("");
  }
}
