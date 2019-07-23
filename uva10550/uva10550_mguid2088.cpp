#include <iostream>

int main() {
  int x1, x2, x3, x4;

  std::cin >> x1 >> x2 >> x3 >> x4;

  while(x1 || x2 || x3 || x4) {
    std::cout << (1080 + ((x1 - x2 + 40) % 40 + (x3 - x2 + 40) % 40 + (x3 - x4 + 40) % 40) * 9) << '\n';
    std::cin >> x1 >> x2 >> x3 >> x4;
  }
}
