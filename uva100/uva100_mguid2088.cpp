#include <cstdio>
#include <unistd.h>
#include <cstdint>
#include <chrono>
#include <unordered_map>

std::unordered_map<uint32_t, uint32_t> seen;

uint32_t cycle_count(uint32_t n) {
  if(n == 1) {
    return 1;
  } else if(n%2 == 0) {
    return 1 + cycle_count(n / 2);
  } else {
    return 1 + cycle_count((n*3)+1);
  }
  return 0;
}

int main() {
  auto begin = std::chrono::high_resolution_clock::now();
  uint32_t i, j, max, tmp_max;
  auto end = std::chrono::high_resolution_clock::now();
  auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
  printf("initialize 4 ints: %f\n", dur/1E9);
  std::unordered_map<uint32_t, uint32_t>::iterator it;

  char buf[4096];
  char *pos = buf;
  seen[1] = 1;
  while(scanf("%u", &i) != EOF) {
    max = 0;
    scanf("%u", &j);
    bool swap = false;
    begin = std::chrono::high_resolution_clock::now();
    if(j<i) {
      i = i^j;
      j = i^j;
      i = j^i;
      swap = true;
    }
    end = std::chrono::high_resolution_clock::now();
    dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
    printf("swap time: %f\n", dur/1E9);

    begin = std::chrono::high_resolution_clock::now();
    for(uint32_t k = i; k <= j; k++) {
      it = seen.find(k);
      if(it != seen.end()) {
        tmp_max = it->second;
      }
      else {
        tmp_max = cycle_count(k);
        seen[k] = tmp_max;
      }
      if(tmp_max > max) max = tmp_max;
    }
    end = std::chrono::high_resolution_clock::now();
    dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
    printf("inner loop time: %f\n", dur/1E9);

    if(swap) {
      pos += sprintf(pos, "%u %u %u\n", j, i, max);
    } else {
      pos += sprintf(pos, "%u %u %u\n", i, j, max);
    }
  }

  begin = std::chrono::high_resolution_clock::now();
  write(1, buf, pos-buf);
  end = std::chrono::high_resolution_clock::now();
  dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count();
  printf("write time: %f\n", dur/1E9);
  return 0;
}
