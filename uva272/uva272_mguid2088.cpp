#include <string>
#include <iostream>
#include <cstdio>
#include <unistd.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  bool left = true;
  char buf[4096];
  char* fp = buf + 4056;
  char* pos = buf;
  for(std::string line; std::getline(std::cin, line); ) {
    for(char s: line) {
      if(s == '\"') {
        if(left) {
          pos += sprintf(pos, "``");
        } else {
          pos += sprintf(pos, "''");
        }
        left = !left;
      } else {
        pos += sprintf(pos, "%c", s);
      }
    }
    pos += sprintf(pos, "\n");
    if(pos >=fp) {
      write(1, buf, pos-buf);
      pos = buf;
    }
  }
  if( pos > buf ) write(1, buf, (pos)-buf);
  return 0;
}
