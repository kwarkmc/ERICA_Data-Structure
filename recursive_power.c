#include <stdio.h>
#include <time.h>

double power(double, int);

int main() {
  clock_t start, finish;
  double duration, x, result;
  int n, i;
  printf("input x : ");
  scanf("%lf", &x);
  printf("input n : ");
  scanf("%d", &n);

  start = clock();
  for (i=0;i<10;i++) {
    result = power(x, n);
    printf("%lf^%d = %lf\n", x, n, result);
  }
  finish = clock();
  duration = (double)(finish-start)/CLOCKS_PER_SEC;
  printf("%f seconds\n", duration);
  return 0;
}

double power(double x, int n) {
  if (n==0) 
    return 1;
  else if ((n%2) == 1) {
    return power(x*x, (n-1)/2);
  }
  else {
    return (power(x*x, n/2));
  }
}
