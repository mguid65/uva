#include <cstdio>
#include <cmath>
#include <array>
#include <algorithm>

int main () {
  std::array<int,3> input;
  while(scanf(" %d %d %d ", &input[0], &input[1], &input[2]) && input[0] != 0) {
    std::sort(input.begin(), input.end());
    if(pow(input[2],2) == (pow(input[0],2) + pow(input[1],2))) puts("right");
    else puts("wrong");
  }
}
