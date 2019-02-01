#include <iostream>
#include <unordered_map>

std::unordered_map<char, std::string> pattern{
  {'0', "76\n"},
  {'1', "16\n"},
  {'2', "56\n"},
  {'3', "96\n"},
  {'4', "36\n"},
  {'5', "76\n"},
  {'6', "16\n"},
  {'7', "56\n"},
  {'8', "96\n"},
  {'9', "36\n"}
};

int main() {
  std::ios_base::sync_with_stdio(false);
  int cases;
  std::cin >> cases;
  std::string line;
  cases++;
  while(cases--) {
    std::getline(std::cin, line);
    if(line == "0") std::cout << "1\n";
    else if (line == "1") std::cout << "66\n";
    else std::cout << pattern[line[line.length()-1]];
  }
}
