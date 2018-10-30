#include <cstdio>
#include <string>

unsigned int reverse_integer(unsigned int num) {
  int rev_num = 0;
  while (num > 0) {
    rev_num = rev_num*10 + num%10;
    num = num/10;
  }
  return rev_num;
}

bool is_pal(const std::string& s)
{
  int size = s.size();
  for(int i = 0; i < size / 2; ++i) {
    if(s[i] != s[size - 1 - i]) return false;
  }
  return true;
}

int main () {
  unsigned int n, i, count;

  scanf("%u", &n);

  for(; n > 0; n--) {
    count = 0;
    scanf("%u", &i);
    while(count == 0 || !is_pal(std::to_string(i))) {
      i += reverse_integer(i);
      count++;
    }
    printf("%d %u\n", count, i);
  }
}
