#include <iostream>
#include <regex>

int main() {
  std::ios_base::sync_with_stdio(false);

  std::string input;

  std::getline(std::cin,input);
  while (std::getline(std::cin, input)) {
    if (input.length() == 5) {
	std::cout << "3";
    } else if (std::regex_match (input, std::regex(".ne")) ||
	std::regex_match (input, std::regex("o.e")) ||
 	std::regex_match (input, std::regex("on.")) ) {
	  std::cout << "1";
    } else if (std::regex_match (input, std::regex(".wo")) ||
	std::regex_match (input, std::regex("t.o")) ||
	std::regex_match (input, std::regex("tw.")) ) {
	  std::cout << "2";
    }
    std::cout << '\n';
  }
}
