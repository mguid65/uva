#include <cstdio>
#include <cstdlib>

int main() {
  int num = 0, e, p, k, r, i;
  long tmp, pk, rounds;
  char c;
  char line[256];
  //size_t size = sizeof(line);
  while((c = getchar_unlocked()) >= '0') {
    num = (num << 3) + (num << 1) + (c & 0x0F);
  }
  for(int cases = 1; cases <= num; cases++) {
    if(fgets_unlocked(line, 256, stdin) == nullptr) break;
    //printf("%s\n", line);
    e = p = k = r = i = 0;
    for(;;i++) {
      if(line[i] == ' ') break;
      e = (e * 10) + (line[i] & 0xF);
    }
    i++;
    for(;;i++) {
      if(line[i] == ' ') break;
      p = (p * 10) + (line[i] & 0xF);
    }
    i++;
    for(;;i++) {
      if(line[i] == ' ') break;
      k = (k * 10) + (line[i] & 0xF);
    }
    i++;
    for(;;i++) {
      if(line[i] < '0') break;
      r = (r * 10) + (line[i] & 0xF);
    }
    pk = p * k;
    if(pk >= e) {
      tmp = (e + p - 1) / p;
      //tmp = ((e - 1) / p) + 1;
    } else if (pk <= r ){
      tmp = -1;
    } else {
      e -= pk;
      pk -= r;
      rounds = (e / pk);
      e -= (rounds * pk);
      tmp = (1 + rounds) * k;
      if (e > 0) tmp += ((e + r + p - 1) / p);
    }
    printf("Case %d: %ld\n", cases, tmp);
  }
}
