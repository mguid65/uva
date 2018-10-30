#include <cstdio>

int main() {
  int c,n;
  float count, avg;
  scanf("%d\n", &c);
  for(;c > 0; c--) {
    count = avg = 0;
    scanf("%d", &n);
    float student_grades[n];
    for(int i = 0; i < n; i++) {
      scanf("%f ", &student_grades[i]);
      avg+= student_grades[i];
    }
    avg/=n;
    for(int i = 0; i < n; i++) {
      if(student_grades[i] > avg) count++;
    }
    printf("%.3f%%\n", (count/n)*100);
  }
}
