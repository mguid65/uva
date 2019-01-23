#include <cstdio>
#include <algorithm>

char c;

inline void get_int(int& i, int& j) {
  while((c=getchar_unlocked()) >= '0') i = (i * 10) + (c & 0xF);
  while((c=getchar_unlocked()) >= '0') j = (j * 10) + (c & 0xF);
}

int main () {
    int i, j;
    while (true) {
        i = j = 0;
        //printf("helo\n");
        get_int(i, j);
        if (c == -1) break;
        //printf("%d %d\n", i, j);
        int temp_i = i;
        int temp_j = j;
        if ( i > j ) std::swap (i, j);
        int max_cycle_length = 0;
        int cycle_length;
        while ( i <= j ) {
            unsigned int n = i;
            cycle_length = 1;
            while ( n != 1 ) {
                if ( n % 2 == 1 ) n = 3 * n + 1;
                else n /= 2;
                cycle_length++;
            }
            if ( cycle_length > max_cycle_length )
                max_cycle_length = cycle_length;
            i++;
        }
        printf ("%d %d %d\n", temp_i, temp_j, max_cycle_length);
    }
}

