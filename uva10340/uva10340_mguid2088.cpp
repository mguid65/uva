#include <iostream>
#include <string>

int main () {
  std::ios_base::sync_with_stdio(false);

  bool good = true;
  std::string word_1;
  std::string word_2;
  std::cin >> word_1 >> word_2;
  while(!std::cin.eof()) {
    for(char &c: word_1) {
      std::size_t found = word_2.find(c);
      if(word_2.find_first_of(c) == std::string::npos) {
        good = false;
        break;
      } else {
        word_2 = word_2.substr(found+1);
      }
    }
    if(good) std::cout << "Yes\n";
    else std::cout << "No\n";
    good = true;
    std::cin >> word_1 >> word_2;
  }
}
