#include <cstdio>
#include <unistd.h>
#include <cstdint>
#include <unordered_map>

std::unordered_map<uint32_t, uint32_t> seen{{1, 1}};

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
  uint32_t i, j, l, max, tmp_max;
  std::unordered_map<uint32_t, uint32_t>::iterator it;

    l = 0;
    char buf[4096];
    char *pos = buf;
    seen[1] = 1;
    while(scanf("%u", &i) != EOF) {
      max = 0;
      scanf("%u", &j);
      bool swap = false;
      if(j<i) {
        i = i^j;
        jd = i^j;
        i = j^i;
        swap = true;
      }

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

    if(swap) {
      pos += sprintf(pos, "%u %u %u\n", j, i, max);
    } else {
      pos += sprintf(pos, "%u %u %u\n", i, j, max);
    }
  }
  write(1, buf, pos-buf);
}




