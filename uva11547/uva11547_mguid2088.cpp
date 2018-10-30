#include <cstdio>
#include <string>

int main() {
  int t, n;
  scanf("%d\n", &t);
  for(;t > 0; t--) {
    scanf("%d\n", &n);
    n = (((((n * 567)/9) + 7492) * 235) / 47) - 498;
    std::string tmp = std::to_string(n);
    printf("%c\n", tmp[tmp.length()-2]);
  }
}
