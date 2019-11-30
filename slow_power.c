#include <stdio.h>
#include <time.h>

void slow_power(double, int);

int main() {
  clock_t start, finish;
  double duration, x;
  int n, i;

  printf("input x : ");
  scanf("%lf", &x);
  printf("input n : ");
  scanf("%d", &n);

  start = clock();
  for (i=0;i<10;i++)
    slow_power(x,n);
  finish = clock();

  duration = (double)(finish-start) / CLOCKS_PER_SEC;

  printf("%f seconds\n", duration);

  return 0;
}

void slow_power(double x, int n) {
  int i;
  double r = 1.0;

  for (i=0;i<n;i++) {
    r = r*x;
  } 

  printf("%lf^%d = %lf\n", x, n, r);
}
