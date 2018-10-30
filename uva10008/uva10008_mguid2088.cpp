#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main () {
  size_t n;
  char c;
  std::unordered_map<char, size_t> char_map;
  std::vector<std::pair<char, size_t>> char_map_sort;
  scanf("%lu\n", &n);
  while((c = getchar_unlocked()) != EOF) {
    if(c < '{' && c > '`') c -= (char)32;
    if(c > '@' && c < '[') char_map[c]++;
  }

  for(auto char_pair: char_map) {
    char_map_sort.push_back(char_pair);
  }

  std::sort(char_map_sort.begin(), char_map_sort.end(),
    [](const std::pair<char, size_t> a, const std::pair<char, size_t> b) {
      if(a.second > b.second) {
        return true;
      } else if (a.second == b.second) {
        return a.first < b.first;
      } return false;
    });
  for(std::pair<char, size_t> char_mapping: char_map_sort) {
    printf("%c %lu\n", char_mapping.first, char_mapping.second);
  }
}
