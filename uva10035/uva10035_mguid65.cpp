#include <cstdio>

int main() {
  unsigned long long m,n,rem_m,rem_n,decider=0,sum,count;
  while((scanf("%llu%llu",&m,&n))!=EOF) {
    if(m==0 && n==0) break;
    count = 0;
    while(m!=0 || n!=0) {
      rem_m=m%10;
      rem_n=n%10;
      if(decider == 1) rem_m++;
        sum = rem_m+rem_n;
        decider = 0;
        if(sum >= 10) {
          count++;
          decider++;
        }
        m/=10;
        n/=10;
    }
    decider = 0;
    if(count==0) {
      printf("No carry operation.\n");
    } else if(count == 1) {
      printf("%d carry operation.\n", 1);
    } else {
      printf("%llu carry operations.\n",count);
    }
  }
}

