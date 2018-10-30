#include <cstdio>
#include <string>
#include <cstring>
int main () {
  char ans[4] = "BCG";
  char bottleType[3] = { 'B', 'G', 'C' };
  int permutations[6][3] = {
    { 0, 1, 2 },
    { 0, 2, 1 },
    { 1, 0, 2 },
    { 1, 2, 0 },
    { 2, 0, 1 },
    { 2, 1, 0 }
  };

  int bottles[3][3];

  while (scanf("%d %d %d %d %d %d %d %d %d", &bottles[0][0], &bottles[0][1], &bottles[0][2], \
                                             &bottles[1][0], &bottles[1][1], &bottles[1][2], \
                                             &bottles[2][0], &bottles[2][1], &bottles[2][2] ) != EOF) {
    int min_count = -1;
    char min_perm[4] = "   ";
    for (int i = 0; i < 6; i++) {
        int count = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (permutations[i][j] != k) {
                    count += bottles[j][k];
                }
            }
        }
        ans[0] = bottleType[permutations[i][0]];
        ans[1] = bottleType[permutations[i][1]];
        ans[2] = bottleType[permutations[i][2]];

        if (min_count == -1 || count < min_count || (count == min_count && strcmp(ans, min_perm) < 0)) {
            min_count = count;
            strcpy(min_perm,ans);
        }
    }
    printf("%c%c%c %d\n",min_perm[0], min_perm[1], min_perm[2], min_count);
  }
}
