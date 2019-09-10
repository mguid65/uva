#include <iostream>


int main() {
  int cases, l, w, h;
  std::cin >> cases;

  for(int i = 1; i <= cases; i++) {
    std::cin >> l >> w >> h;
    if((l <=20) && (h <= 20) && (w <= 20)) std::cout << "Case " << i << ": good\n";
    else std::cout  << "Case " << i << ": bad\n";

  }
}
