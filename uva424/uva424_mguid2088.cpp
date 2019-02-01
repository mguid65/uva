#include <string>
#include <iostream>
#include <array>


int main () {
  std::string line;
  std::array<int, 201> sum={0};
  int i, j, length;
  while(std::getline(std::cin, line) && line != "0") {
    length = line.length();
    for(int i = 0, j = length-1; i < length; i++, j--) {
      sum[i] += line[j] - '0';
    }
  }

  for(i = 0; i < 200; i++) {
    if(sum[i] >=10) {
      sum[i+1] += sum[i]/10;
      sum[i] %= 10;
    }
  }
  i = 200;
  while(sum[i] == 0 && i >= 0) i--;
  if(i == -1) std::cout << "0";
  for(; i >= 0; i--) {
    std::cout << sum[i];
  }
  std::cout << '\n';
}
