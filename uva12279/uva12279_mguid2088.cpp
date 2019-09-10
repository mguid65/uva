#include <iostream>

int main() {
  int n{1}, count = 0;

  std::cin >> n;
  while (n) {
    count++;
    int sum = 0, t;
    for (int i = 0; i < n; i++) {
      std::cin >> t;
      if (t > 0) sum++;
      else sum--;
    }
    std::cout << "Case " << count << ":" << sum << '\n';
    std::cin >> n;
  }

}
