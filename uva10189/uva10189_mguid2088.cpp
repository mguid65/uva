#include <cstdio>
#include <climits>
int main() {
  char c;
  int count = 1;
  int i, j, k, l;
  scanf("%d %d\n", &i, &j);

  while(i!=0 && j!=0) {
    if(count != 1) printf("\n");
    printf("Field #%d:\n", count++);
    int field[i+2][j+2] = {0};
    for(k = 1; k < i+1; k++) {
      for(l = 1; l < j+1; l++) {
        scanf("%c", &c);
        if(c == '*') {
          field[k][l] = -1;
          field[k-1][l-1]+=field[k-1][l-1] == -1? 0 : 1;
          field[k-1][l]+=field[k-1][l] == -1? 0 : 1;
          field[k][l-1]+=field[k][l-1] == -1? 0 : 1;
          field[k+1][l]+=field[k+1][l] == -1? 0 : 1;
          field[k+1][l+1]+=field[k+1][l+1] == -1? 0 : 1;
          field[k][l+1]+=field[k][l+1] == -1? 0 : 1;
          field[k-1][l+1]+=field[k-1][l+1] == -1? 0 : 1;
          field[k+1][l-1]+=field[k+1][l-1] == -1? 0 : 1;
        }
      }
      scanf("\n");
    }
    for(k = 1; k < i+1; k++) {
      for(l = 1; l < j+1; l++) {
        if(field[k][l]== < 0) {
          printf("*");
        } else {
          printf("%d", field[k][l]);
        }
      }
      printf("\n");
    }
    scanf("%d %d\n", &i, &j);
  }
}
