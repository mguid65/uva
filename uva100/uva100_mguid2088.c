#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t seen[10000];

uint32_t cycle_count(uint32_t n) {
  uint32_t count = 0;
  uint32_t k = n;
  while(n != 1) {
    if(n <= 9999) {
      if(seen[n] != 0) {
        count+=seen[n];
        break;
      }
    }
    if(n%2 == 0) {
      n /= 2;
      count++;
    } else {
      n = ((n*3)+1)/2;
      count+=2;
    }
  }
  if(k <= 9999)
    seen[k] = count;
  return count+1;
}

int main() {
  uint32_t i;
  uint32_t j;
  uint32_t max;
  uint32_t tmp_max;
  seen[1] = 1;
  
  char buf[4096];
  char *pos = buf;

  while(scanf("%u", &i) != EOF) {
    scanf("%u", &j);
    bool swap = false;
    if(j<i) {
      i = i^j;
      j = i^j;
      i = j^i;
      swap = true;
    }
    max = cycle_count(i);
    uint32_t k;
    for(k = i + 1; k <= j; k++) {
      if(k > 9999){
        tmp_max = cycle_count(k);
      } else if(seen[k] != 0){
        tmp_max = seen[k]+1;
      } else {
        tmp_max = cycle_count(k);
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

  return 0;
}
