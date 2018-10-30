#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

int main () {
  std::string line;
  std::getline(std::cin, line);
  int count;
  while(!std::cin.eof()) {
    count = 0;
    std::replace_if(line.begin(), line.end(), [] (char c) {
      if (c == ' ') return false;
      return !std::isalpha(c);
    }, ' ');
    std::stringstream ss(line);
    std::string word;
    while(ss >> word) {
      count++;
    }
    printf("%d\n", count);
    std::getline(std::cin, line);
  }

}
