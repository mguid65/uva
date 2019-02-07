#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  int input;
  while(true) {
    std::cin >> input;
    std::ostringstream output;

    if(input < 0) break;
    while(true) {
      output << (input % 3);
      input /= 3;
      if(input == 0) break;
    }
    std::string out = output.str();
    std::reverse(out.begin(), out.end());
    std::cout << out << "\n";
  }
}


