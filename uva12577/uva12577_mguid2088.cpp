#include <iostream>

int main() {

  std::string word;
  int c = 1;
  while(std::cin >> word && word != "*") {
    std::cout << "Case " << c << ": " << (word == "Hajj" ? "Hajj-e-Akbar\n" : "Hajj-e-Asghar\n");
    c++;
  }
}
