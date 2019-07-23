#include <iostream>

int main() {
  int t, n, x;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    int max = 0, min = 99;
    while (n--) {
      std::cin >> x;
      if (x > max) max = x;
      if (x < min) min = x;
    }
        std::cout << (max-min)*2 << '\n';
  }
  return 0;
}
