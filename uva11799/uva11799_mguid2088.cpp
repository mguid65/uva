#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int c, n;
  scanf("%d\n", &c);
  for (int i = 0; i < c; i++) {
    scanf("%d ", &n);
    std::vector<int> students(n);
    for (;n > 0; n--) {
      scanf("%d ", &students[n-1]);
    }
    printf("Case %d: %d\n", i+1, *std::max_element(students.begin(), students.end()));
  }

}
