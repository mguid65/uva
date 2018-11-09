#include <map>
#include <iostream>

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cout.precision(4);
  std::cin.tie(nullptr);

  int cases, count;

  std::string tree;
  std::cin >> cases;

  std::getline(std::cin, tree);
  std::getline(std::cin, tree);

  std::map<std::string, int> trees;
  while(cases--) {
    count = 0;

    while(std::getline(std::cin, tree)) {
      if(tree.empty()) break;
      trees[tree]++;
      count++;
    }

    for(auto &x: trees) std::cout << std::fixed << x.first + ' ' << x.second * 100.0/count << '\n';
    //for(auto const& x: trees) printf("%s %.4f\n", x.first.c_str(), x.second * 100.0/count); //cant use this if sync_with_stdio(false)
    trees.clear();

    if(cases > 0) std::cout << '\n';
  }
}
