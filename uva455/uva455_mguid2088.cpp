#include <array>
#include <iostream>
#include <string>

int period(const std::string& s) {
  std::array<char, 1000> pattern;
  pattern[0] = -1;
  int j = -1;
  for (int i = 1; i < s.length(); ++i) {
    while (j >= 0 && s[j + 1] != s[i]) j = pattern[j];
    if (s[j + 1] == s[i]) ++j;
    pattern[i] = j;
  }
  return j;
}

int main() {
  int n_test;
  std::string input;
  input.reserve(1000);
  std::cin >> n_test;

  std::getline(std::cin, input);
  std::getline(std::cin, input);

  while (n_test--) {
    std::getline(std::cin, input);
    int t = period(input);
    int l = input.length();
    if (l % (l - t - 1))
      std::cout << l << '\n';
    else
      std::cout << l - t - 1 << '\n';
    std::getline(std::cin, input);
    if (n_test) std::cout << '\n';
  }
}

