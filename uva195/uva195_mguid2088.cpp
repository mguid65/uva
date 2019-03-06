#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;
using std::next_permutation;
using std::tolower;

int main() {
  std::ios_base::sync_with_stdio(false);
  string in;

  size_t cases;
  cin >> cases;

  auto cmp = [](const char& a, const char& b) {
    if(tolower(a) == tolower(b)) return a < b;
    return tolower(a) < tolower(b);
  };

  while(cases--) {
    cin >> in;
    std::sort(in.begin(), in.end(),cmp);
    do {
      cout << in << '\n';
    } while(std::next_permutation(in.begin(), in.end(), cmp));
  }
}
