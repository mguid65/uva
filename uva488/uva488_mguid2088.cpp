#include <cstdio>
#include <unistd.h>

int main() {
  int c, i, j, tmp=0;
  char buf[4096];
  char * pos = buf;
  scanf("%d\n\n", &c);
  for(int h = 0;h < c; h++) {
    scanf("%d\n%d\n\n", &i, &j);
    tmp = 0;
    for(int k = 0; k < (2*i) - 1; k++) {
      if(k < i) {
        tmp++;
      } else if(k >= i) {
        tmp--;
      }
      for(int l=0;l<tmp; l++) {
        pos += sprintf(pos, "%d", tmp);
      }
      pos += sprintf(pos, "\n");
      if (k == (2 * i) - 2){
        pos += sprintf(pos, "\n");
      }
    }

    for(;j > 0; j--) {
      if (h == (c-1) && j == 1) {
        write(1, buf, pos - buf - 1);
      } else {
        write(1, buf, pos - buf);
      }
    }
    pos = buf;
  }
}
