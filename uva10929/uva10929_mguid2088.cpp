#include <cstdio>

char input[1001];

int main () {
  input[1000] = '\0';
  char c;
  int i, count;
  while(true) {
    while((input[0] = getchar_unlocked()) < 48) { }
    if((input[1] = getchar_unlocked()) == '\n') break;
    count = 2;
    while((input[count] = getchar_unlocked()) >= '0') {
      count++;
    }
    input[count] = '\0';
    bool cycle = true;
    int alternating_sum = 0;
    for(int i = 0; i < count; i++) {
      if(cycle) {
        alternating_sum += (int)(input[i] & 0xF);
        cycle = false;
      }
      else {
        alternating_sum -= (int)(input[i] & 0xF);
        cycle = true;
      }
    }
    if(alternating_sum % 11 == 0) printf("%s is a multiple of 11.\n", (char*)input);
    else printf("%s is not a multiple of 11.\n", (char*)input);
  }
}
