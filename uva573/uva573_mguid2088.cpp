#include <cstdio>

int main() {
  int h, u, d, f, day;
  float current_height, fatigue;

  while ( scanf(" %d %d %d %d ", &h, &u, &d, &f) && h != 0 ) {
    day = 0;
    current_height = 0;
    float climb_height = u;
    fatigue = f / 100.0 * climb_height;

    while ( true ) {
      day++;
      current_height += climb_height;

      if ( current_height > (double)h ) {
        printf("success on day %d\n", day);
        break;
      }
      current_height -= (double)d;
      if ( current_height < 0 ) {
        printf("failure on day %d\n", day);
        break;
      }

      climb_height -= (fatigue);
      if ( climb_height < 0 ) climb_height = 0;
    }
  }
}

