#include <cstdio>

int main () {
  unsigned long num_case, num_farmer, i, garbage, k, burdon;
  scanf("%lu", &num_case);
  for(;num_case > 0; num_case--) {
    scanf("%lu", &num_farmer);
    burdon=0;
    for(;num_farmer > 0; num_farmer--){
      scanf("%lu %lu %lu", &i, &garbage, &k);
      burdon+= i*k;
    }
    printf("%lu\n", burdon);
  }
}
