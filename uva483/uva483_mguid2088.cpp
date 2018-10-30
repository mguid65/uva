#include <iostream>
#include <algorithm>
#include <sstream>
#include <unistd.h>

int main () {
  std::string word;
  std::string line;
  std::getline(std::cin, line);
  std::cout << line << '\n';
  while(!std::cin.eof()) {
    std::stringstream ss(line);
    ss >> word;
    bool first = true;
    while(!ss.eof()) {
      if(!first) {
        std::cout << ' ';
      }
      std::reverse(word.begin(), word.end());
      std::cout << word;
      ss >> word;
      first = false;
    }
    std::cout << '\b';
    std::cout << '\n';
    std::getline(std::cin, line);
    std::cout << line << '\n';
    usleep(5000);
  }
}
