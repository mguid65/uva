#include <unordered_map>
#include <iostream>
#include <string>

std::unordered_map<char, char> letter_correction_map {
  {'W','Q'},
  {'E','W'},
  {'R','E'},
  {'T','R'},
  {'Y','T'},
  {'U','Y'},
  {'I','U'},
  {'O','I'},
  {'P','O'},
  {'[','P'},
  {']','['},
  {'\\',']'},
  {'S','A'},
  {'D','S'},
  {'F','D'},
  {'G','F'},
  {'H','G'},
  {'J','H'},
  {'K','J'},
  {'L','K'},
  {';','L'},
  {'\'',';'},
  {'X','Z'},
  {'C','X'},
  {'V','C'},
  {'B','V'},
  {'N','B'},
  {'M','N'},
  {',','M'},
  {'.',','},
  {'/','.'},
  {'1','`'},
  {'2','1'},
  {'3','2'},
  {'4','3'},
  {'5','4'},
  {'6','5'},
  {'7','6'},
  {'8','7'},
  {'9','8'},
  {'0','9'},
  {'-','0'},
  {'=','-'},
  {' ',' '}
};

int main() {
  std::ios_base::sync_with_stdio(false);

  std::string line;
  std::getline(std::cin, line);
  while(!std::cin.eof()) {
    for(char &c: line) {
      std::cout << letter_correction_map[c];
    }
    std::cout << '\n';
    std::getline(std::cin, line);
  }
}
