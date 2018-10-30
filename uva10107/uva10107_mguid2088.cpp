#include <cstdio>
#include <algorithm>
#include <climits>

int main() {
  unsigned int index=1;
  unsigned int li[10001];

  while(scanf("%d\n", &li[index]) != EOF) {
    std::sort(li,li+index+1);
    if(index == 1) printf("%d\n", li[1]);
    else if(index % 2 == 0) {printf("%d\n",(li[index/2] + li[(index/2)+1])/2);}
    else {printf("%d\n",li[(index/2)+1]);}
    index++;
  }
}
