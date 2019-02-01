#include <iostream>
#include <string>
#include <cmath>

int main () {
  std::string line;
  long sum;
  while(std::getline(std::cin, line) && line != "0") {
    sum = 0;
    for(int i = 0; i < line.length(); i++) {
      sum += (line[i]-'0') * (pow(2, i+1)-1);
    }
    std::cout << sum << '\n';
  }
}
