#include <iostream>

using std::string;
using std::getline;
using std::cout;
using std::cin;

int main() {
  string s;
  while ( getline(cin, s) ) cout << s << '\n';
}
