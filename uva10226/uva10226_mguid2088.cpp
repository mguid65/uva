#include <map>
#include <iostream>

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cout.precision(4);
  std::cin.tie(NULL);
  int cases, count;
  std::map<std::string, int> trees;
  std::string tree;
  std::cin >> cases;
  std::getline(std::cin, tree);
  std::getline(std::cin, tree);
  while(cases--) {
    count = 0;
    while(std::getline(std::cin, tree)) {
      if(tree.empty()) break;
      trees[tree]++;
      count++;
    }
    for(auto const& x: trees) std::cout << std::fixed << x.first + ' ' << x.second * 100.0/count << '\n';
    //for(auto const& x: trees) printf("%s %.4f\n", x.first.c_str(), x.second * 100.0/count);
    trees.clear();
    if(cases > 0) {
      std::cout << '\n';
    }
  }
}
