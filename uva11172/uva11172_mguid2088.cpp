#include <cstdio>

int main() {
  long int i, j, k;
  scanf("%ld\n",&i);
  for (i=i;i>0;i--) {
    char res = '=';
    scanf("%ld %ld\n", &j, &k);
    if (j > k) res = '>';
    if (j < k) res = '<';
    printf("%c\n", res);
  }
}
