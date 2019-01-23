#include <cstdio>

int main() {
  int in;
  puts("PERFECTION OUTPUT");
  while(scanf("%d", &in) && in != 0) {
    int result = 0;
    for(int i = 1; i < in; i++) {
      if(in % i == 0) result += i;
    }
    if(result < in) {
      printf("%5d  DEFICIENT\n", in);
    } else if(result > in) {
      printf("%5d  ABUNDANT\n", in);
    } else {
      printf("%5d  PERFECT\n", in);
    }
  }
  puts("END OF OUTPUT");
}
