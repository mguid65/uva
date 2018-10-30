#include <string>
#include <iostream>

int main() {
  std::string line;
  std::ios_base::sync_with_stdio(false);
  while (std::getline(std::cin, line)) {
    int line_length = line.size();
    int cur;
    std::string sub;
    for (int i = 0; i < line_length; i++) {
      cur = 0;
      if (line[i] != ' ') {
        while (line[i + cur] != ' ' && i + cur < line_length) {
          cur++;
        }
        for (int j = (i + cur) - 1; i <= j && j < line_length; j--) {
          std::cout << line[j];
        }
        i += cur - 1;
      } else {
        std::cout << line[i];
      }
    }
    std::cout << '\n';
  }
}
